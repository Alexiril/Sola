"""
This file loads automatically all third-party files needed
"""

from enum import Enum
from json import loads
from pathlib import Path
from shutil import copyfile, copytree, which, rmtree
from subprocess import STDOUT, run
from sys import stdout, argv


vendored: dict[str, dict[str, str]] = {}


class VendoredType(Enum):
    GITREPO = "Git repository"
    # TODO: make archive / folder type of vendor


def get_git_executable() -> str:
    git_executable = which("git")
    if git_executable is None:
        raise RuntimeError(
            "Git is not found in the system. Please, check that it is "
            "installed correctly and is available via PATH environment variable."
        )
    return git_executable


def git_action(args: list[str], cwd: Path) -> None:
    run(
        [get_git_executable(), *args],
        stdout=stdout,
        stderr=STDOUT,
        check=True,
        cwd=cwd,
    )


def download_via_git(actual_path: Path, branch: str, repository: str) -> None:
    git_action(["clone", "--depth", "1", "-b", branch, repository, actual_path.as_posix()], Path("."))


def update_via_git(actual_path: Path) -> None:
    # We don't care about local changes
    # They should be placed into patch folder anyway
    git_action(["reset", "--hard", "HEAD"], actual_path)
    git_action(["pull"], actual_path)


def load(name: str, path: str, vendored_type: VendoredType, args: dict[str, str], update: bool) -> None:
    actual_path = Path("vendor") / path
    print(f"Working on {name}", actual_path.absolute().as_posix())
    vendored[name] = args
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
                download_via_git(actual_path, args["branch"], args["url"])
            print(f"{name} is downloaded.")
    except Exception as e:
        if del_folder_on_error:
            rmtree(actual_path, True)
        raise e


def patch(patch: str, vendored_path: str, patch_place: str) -> None:
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


def do_action(action: dict[str, str], update: bool) -> None:
    global vendored
    if action["type"] == "load-git":
        load(action["name"], action["path"], VendoredType.GITREPO, action, update)
    if action["type"] == "patch":
        patch(action["patch"], vendored[action["vendored"]]["path"], action["path"])


def main() -> None:
    update = True
    for arg in argv[1:]:
        if arg == "--no-update":
            update = False
            print("Update is disabled. Vendored libraries will not be updated.")
    try:
        vendor_dir = Path(".") / "vendor"
        vendored = vendor_dir / "vendored.json"
        with open(vendored, mode="r", encoding="utf-8") as inp:
            actions: list[dict[str, str]] = loads(inp.read())
        for action in actions:
            do_action(action, update)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
