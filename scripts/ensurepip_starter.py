from os import name
from pathlib import Path
from subprocess import run
from sys import argv

def main() -> None:
    # Windows only now
    if name != "nt":
        return

    new_python_home = Path(argv[1])
    for file_name in ["pip.exe", "pip3.exe"]:
        if (new_python_home / "Scripts" / file_name).is_file():
            print("-- PIP executable found. Skipping installation")
            return
    if not (python_executable := new_python_home / "python_d.exe").exists():
        python_executable = new_python_home / "python.exe"
    run([
        python_executable,
        "-m",
        "ensurepip",
        "--upgrade"
    ], cwd=new_python_home, env={
        "PYTHONHOME": new_python_home.as_posix()
    }, check=True)

    print("-- PIP is installed")

if __name__ == "__main__":
    main()
