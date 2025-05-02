from typing import Any
from Sola.Interfaces.IProjectLoader import IProjectLoader
from Sola.Exceptions.ProjectImportException import ProjectImportException


class ProjectLoader(IProjectLoader):
    __slots__ = ["data_file"]

    def __init__(self, project_dir: str) -> None:
        super().__init__(project_dir)
        if not (data_file := (self.project_dir / "application.json")).is_file():
            raise ProjectImportException(
                f"File application.json was not found in {project_dir}"
            )
        self.data_file = data_file

    def load(self) -> dict[str, Any]:
        """Loads the project data from a file"""
        return {}


__all__ = ["ProjectLoader"]
