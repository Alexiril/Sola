from abc import ABCMeta, abstractmethod
from pathlib import Path
from typing import Any

from Sola.Exception.ProjectImportException import ProjectImportException


class IProjectLoader(metaclass=ABCMeta):
    __slots__ = ["project_dir"]

    def __init__(self, project_dir: str) -> None:
        self.project_dir = Path(project_dir)
        if not self.project_dir.is_dir():
            raise ProjectImportException(
                f"Resource '{project_dir}' is not a real existing accessible directory."
            )

    @abstractmethod
    def load(self) -> dict[str, Any]: ...


__all__ = ["IProjectLoader"]
