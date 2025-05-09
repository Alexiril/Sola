"""@package Sola.Initializer
This module contains the Initializer class and the sola_init function.
"""

from sys import version

from SolaAPI import get_engine_version_readable
from SolaAPI.Logger import print_debug


class Initializer:
    """The Initializer class is responsible for initializing the Sola Python API.
    Please, note that this class is not intended to be used directly.
    Instead, it is used internally by the Sola Python API to set up the environment.
    """

    def __init__(self, project_dir: str) -> None:
        """This method is called when the Sola Python API is imported.
        It initializes the Sola Python API and sets up the environment.
        """
        print_debug(
            f"Sola ({get_engine_version_readable()}) Python Interpreter ({version}) "
            f"is initialized for project {project_dir}"
        )


def sola_init(project_dir: str) -> None:
    """Simple function to initialize the Sola Python API.
    This function is not intended to be used directly.
    """
    Initializer(project_dir)


__all__ = ["Initializer", "sola_init"]
