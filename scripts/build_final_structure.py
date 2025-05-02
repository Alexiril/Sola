# This file creates the final structure of the Sola (currently Windows only)
# TODO#5

from os import name
from pathlib import Path
from shutil import rmtree
from sys import argv, version_info


def main() -> None:
    # Support Windows only for now
    if name != "nt":
        return

    _, arch, build_dir, install_dir, lib_dir, bin_dir = argv

    install_bindir = f"{install_dir}/{bin_dir}"

    version = ".".join(map(str, version_info[0:3]))

    print(
        "[Python BuildFinalStructure module]",
        f"Selected Python architecture - {arch}",
        f"Python version               - {version}",
        f"Binary directory             - {build_dir}",
        f"Install binary directory     - {install_bindir}",
        f"Install library directory    - {install_dir}/{lib_dir}",
        sep="\n",
    )

    # SDL3 creates cmake folder in the final artifacts directory.
    # It's good for further usage of the library, like in development,
    # but totally useless in this case.
    if (cmake_dir := Path(install_dir) / "cmake").is_dir():
        rmtree(cmake_dir)

    # We don't need pkgconfig files in the final build on Windows
    if (pkgconfig_dir := Path(install_dir) / "share" / "pkgconfig").is_dir():
        rmtree(pkgconfig_dir)

    # SDL3 forses creation of package config file in library directory.
    # It's good in general case, but is not needed in this case.
    if (libpkgconfig := Path(install_dir) / lib_dir / "pkgconfig").is_dir():
        rmtree(libpkgconfig)


if __name__ == "__main__":
    main()
