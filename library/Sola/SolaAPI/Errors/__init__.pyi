"""@package Sola.SolaAPI.Errors
This module is just a type definition for the Sola Python API Errors.
"""

def raiseWarning(What: str) -> None:
    """Raises warning inside C++ backend. Writes the warning to the log.
    Shows simple popup window with the warning text and okay button.
    """

def raiseError(What: str) -> None:
    """Raises error inside C++ backend. Writes the error to the log.
    Shows simple popup window with the error text and two choises: ignore or quit.
    """

def raiseFatal(What: str) -> None:
    """Raises fatal inside C++ backend. Writes the fatal error to the log.
    Completely stops all the processes in the application, and shows
    simple popup window with the fatal error text and quit button.
    """
