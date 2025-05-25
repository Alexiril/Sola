"""@package Sola.Initializer
This module contains the Initializer class and the sola_init function.
"""

from sys import version

from SolaAPI import getEngineVersionReadable
from SolaAPI.Logger import printDebug


class Initializer:
    """The Initializer class is responsible for initializing the Sola Python API.
    Please, note that this class is not intended to be used directly.
    Instead, it is used internally by the Sola Python API to set up the environment.
    """

    @staticmethod
    def init(ProjectDir: str) -> None:
        """This method is called when the Sola Python API is imported.
        It initializes the Sola Python API and sets up the environment.
        """
        printDebug(
            f"Sola ({getEngineVersionReadable()}) Python Interpreter ({version}) "
            f"is initialized for project {ProjectDir}"
        )


__all__ = ["Initializer"]
