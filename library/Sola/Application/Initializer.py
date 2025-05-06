from sys import version

from Sola.Interfaces.IProjectLoader import IProjectLoader
from SolaAPI import get_engine_version_readable
from SolaAPI.Application import is_app_editor, set_project_configuration
from SolaAPI.Logger import print_debug


class Initializer:
    def __init__(self, project_dir: str) -> None:
        print_debug(
            f"Sola ({get_engine_version_readable()}) Python Interpreter ({version}) "
            "is initialized for project {project_dir}"
        )
        if is_app_editor():
            from Sola.Editor.ProjectLoader import ProjectLoader
        else:
            from Sola.Application.ProjectLoader import ProjectLoader
        loader: IProjectLoader = ProjectLoader(project_dir)
        set_project_configuration(loader.load())


def sola_init(project_dir: str) -> None:
    Initializer(project_dir)


__all__ = ["Initializer", "sola_init"]
