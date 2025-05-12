# This file creates the final structure of the Sola (currently Windows only)
# TODO#5

from os import name
from pathlib import Path
from shutil import copy, rmtree
from sys import argv, version_info


def main() -> None:
    # Support Windows only for now
    if name != "nt":
        return

    _, arch, build_dir, install_dir, lib_dir, bin_dir, vd = argv

    install_bindir = f"{install_dir}/{bin_dir}"

    version = ".".join(map(str, version_info[0:3]))

    print(
        "[Python BuildFinalStructure module]",
        f"Selected Python architecture - {arch}",
        f"Python version               - {version}",
        f"Binary directory             - {build_dir}",
        f"Install binary directory     - {install_bindir}",
        f"Install library directory    - {install_dir}/{lib_dir}",
        f"Vendor directory             - {vd}",
        sep="\n",
    )

    # SDL3 creates cmake folder in the final artifacts directory.
    # It's good for further usage of the library, like in development,
    # but totally useless in this case.
    if (cmake_dir := Path(install_dir) / "cmake").is_dir():
        rmtree(cmake_dir)

    # We don't need pkgconfig files in the final build
    if (pkgconfig_dir := Path(install_dir) / "share" / "pkgconfig").is_dir():
        rmtree(pkgconfig_dir)

    # SDL3 forses creation of package config file in library directory.
    # It's good in general case, but is not needed in this case.
    if (libpkgconfig := Path(install_dir) / lib_dir / "pkgconfig").is_dir():
        rmtree(libpkgconfig)

    # Copying licenses...
    vendor_dir = Path(vd)
    license_dir = Path(install_dir) / "licenses"

    def copy_license(license_for: str, license_path: Path, license_subname: str = "") -> None:
        copy(
            license_path,
            license_dir / f"{license_for}-{license_subname + '-' if license_subname != '' else ''}LICENSE.txt",
        )

    copy_license("Sola", vendor_dir / ".." / "LICENSE")
    copy_license("Capstone", vendor_dir / "capstone" / "LICENSES" / "LICENSE.TXT")
    copy_license("FreeType", vendor_dir / "freetype" / "docs" / "FTL.TXT")
    copy_license("GLFW", vendor_dir / "glfw" / "LICENSE.md")
    copy_license("ImGui", vendor_dir / "imgui" / "LICENSE.txt")
    copy_license("NFD", vendor_dir / "nfd" / "LICENSE")
    copy_license("PPQSort", vendor_dir / "ppqsort" / "LICENSE")
    copy_license("Tracy", vendor_dir / "tracy" / "LICENSE")
    copy_license("Zstd", vendor_dir / "zstd" / "LICENSE")

    # SDL puts its licenses into separate SDL folder. It's nice, but no, thanks.
    # The issue is - if we put all the licenses into separate folders, it's not looking
    # good, because there's only one file in each folder (at least, at the moment of
    # writing this comment).
    copy_license("SDL", license_dir / "SDL3" / "LICENSE.txt")
    rmtree(license_dir / "SDL3")


if __name__ == "__main__":
    main()
