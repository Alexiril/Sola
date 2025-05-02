from typing import Any
from Sola.Interfaces.IProjectLoader import IProjectLoader


class ProjectLoader(IProjectLoader):
    def load(self) -> dict[str, Any]:
        """Loads the project data from an asset pack"""
        raise NotImplementedError(
            "Not working yet. Only editor project loader is implemented"
        )


__all__ = ["ProjectLoader"]
