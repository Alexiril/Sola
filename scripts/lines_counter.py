"""
This file counts all the text lines in the selected folder (recursively) with the selected file extension
"""

# Why does this file even exist?..

from pathlib import Path
from sys import argv
from os import walk
from os.path import join


class ExtensionData:
    lines: int
    code_size: int

    def __init__(self) -> None:
        self.lines = 0
        self.code_size = 0
        self.full_size = 0


def main() -> None:
    """Count the lines of code in the project."""

    if len(argv) < 2:
        print("Usage: python lines_counter.py <path> [<extensions>]")
        print("Example: python lines_counter.py .py .cpp")
        return
    top = Path(argv[1])
    extensions: list[str] = argv[2:] if len(argv) > 2 else [".py", ".pyi", ".cpp", ".hpp"]

    extensions_lines: dict[str, ExtensionData] = {x: ExtensionData() for x in extensions}

    total_lines = 0
    for root, _, files in walk(top):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                with open(join(root, file), "r", encoding="utf-8") as inp:
                    data = inp.readlines()
                    lines = len(data)
                    total_lines += lines
                    extension = "." + file.split(".")[-1]
                    ext_data = extensions_lines[extension]
                    ext_data.lines += lines
                    filesize = inp.tell()
                    ext_data.full_size += filesize
                    # This is the code for declaring the size of the code without comments, unnecessary spaces, and docs
                    # And it doesn't work. No time and no wish to finish it yet
                    if extension in (".py", ".pyi"):
                        pass
                    elif extension in (".cpp", ".hpp"):
                        pass
                    else:
                        # Not even trying to define actual code size
                        ext_data.code_size += filesize

    print(f"Total lines of code in {top.as_posix()}: {total_lines}")  # type: ignore
    for ext, lines in extensions_lines.items():
        print(f"Lines of code in '{ext}' files: {lines.lines}")


if __name__ == "__main__":
    main()
