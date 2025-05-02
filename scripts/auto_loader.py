"""
This file loads automatically all third-party files needed
"""

from enum import Enum
from pathlib import Path
from shutil import copyfile, copytree, which, rmtree
from subprocess import STDOUT, run
from sys import stdout, argv


class VendoredType(Enum):
    GITREPO = "Git repository"
    # TODO#4


def get_git_executable() -> str:
    git_executable = which("git")
    if git_executable is None:
        raise RuntimeError(
            "Git is not found in the system. Please, check that it is "
            "installed correctly and is available via PATH environment variable."
        )
    return git_executable


def download_via_git(actual_path: Path, repository: str) -> None:
    run(
        [
            get_git_executable(),
            "clone",
            "--depth",
            "1",
            repository,
            actual_path.as_posix(),
        ],
        stdout=stdout,
        stderr=STDOUT,
        check=True,
    )


def update_via_git(actual_path: Path) -> None:
    run(
        [
            get_git_executable(),
            "pull",
        ],
        stdout=stdout,
        stderr=STDOUT,
        check=True,
        cwd=actual_path,
    )


def vendored(name: str, path: str, vendored_type: VendoredType, url: str, update: bool) -> None:
    actual_path = Path("vendor") / path
    print(f"Working on {name}", actual_path.absolute().as_posix())
    del_folder_on_error = False
    try:
        if actual_path.is_dir():
            print(f"{name} folder found.")
            if not update:
                return
            if vendored_type == VendoredType.GITREPO:
                update_via_git(actual_path)
            print(f"{name} is successfully updated")
        else:
            del_folder_on_error = True
            print(f"{name} will be downloaded. Please, wait.")
            if vendored_type == VendoredType.GITREPO:
                download_via_git(actual_path, url)
            print(f"{name} is downloaded.")
    except Exception as e:
        if del_folder_on_error:
            rmtree(actual_path, True)
        raise e


def patch_over(patch: str, vendored_path: str, patch_place: str) -> None:
    patches_dir = Path(".") / "vendor" / "patches"
    current_vendored = Path(".") / "vendor" / vendored_path
    if not current_vendored.is_dir():
        raise RuntimeError(
            f"Third party library folder '{vendored_path}' was not found. "
            "The folder should be created before patching it."
        )
    current_patch = patches_dir / patch
    if not current_patch.exists():
        raise RuntimeError(f"Patch '{patch}' was not found in the patches folder")
    final_place = current_vendored / patch_place
    if current_patch.is_dir():
        copytree(current_patch, final_place, dirs_exist_ok=True)
    else:
        copyfile(current_patch, final_place)
    print(f"Patch '{patch}' is embedded to '{vendored_path}' successfully.")


def main() -> None:
    update = True
    for arg in argv[1:]:
        if arg == "--no-update":
            update = False
    vendored(
        "Python",
        "cpython",
        VendoredType.GITREPO,
        "https://github.com/python/cpython.git",
        update,
    )
    patch_over("cpython/CMakeLists.txt", "cpython", "CMakeLists.txt")
    patch_over(
        "cpython/PCbuild",
        "cpython",
        "PCbuild",
    )
    vendored(
        "SDL",
        "sdl",
        VendoredType.GITREPO,
        "https://github.com/libsdl-org/SDL.git",
        update,
    )


if __name__ == "__main__":
    main()
