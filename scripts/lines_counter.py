"""
This file counts all the text lines in the selected folder (recursively) with the selected file extension
"""

# Why does this file even exist?..

from pathlib import Path
from sys import argv
from os import walk
from os.path import join


def main() -> None:
    """Count the lines of code in the project."""

    if len(argv) < 2:
        print("Usage: python lines_counter.py <path> [<extensions>]")
        print("Example: python lines_counter.py .py .cpp")
        return
    top = Path(argv[1])
    extensions = argv[2:] if len(argv) > 2 else [".py", ".pyi", ".cpp", ".hpp"]

    extensions_lines = {x: 0 for x in extensions}

    total_lines = 0
    for root, _, files in walk(top):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                with open(join(root, file), "r", encoding="utf-8") as inp:
                    lines = len(inp.readlines())
                    total_lines += lines
                    extensions_lines["." + file.split(".")[-1]] += lines

    print(f"Total lines of code in {top.as_posix()}: {total_lines}")  # type: ignore
    for ext, lines in extensions_lines.items():
        print(f"Lines of code in '{ext}' files: {lines}")


if __name__ == "__main__":
    main()
