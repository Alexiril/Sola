"""@package Sola.SolaAPI.Graphics
This module is just a type definition for the Sola Python API Graphics.
"""

from collections.abc import Callable
from typing import Literal

class ButtonData:
    """Class representing a button in a message box."""

    def __init__(self, ButtonID: int, IsEscapeDefault: bool, IsEnterDefault: bool, Text: str) -> None:
        """Initialize a button with the given parameters.
        Args:
            ButtonID (int): The ID of the button.
            IsEscapeDefault (bool): Whether this button is the default escape button.
            IsEnterDefault (bool): Whether this button is the default enter button.
            Text (str): The text to display on the button.
        """

def showMessageBox(
    Severity: Literal["none", "info", "warning", "error"],
    Title: str,
    Message: str,
    Buttons: list[ButtonData],
    Callback: Callable[[int], None],
) -> None:
    """Calls WindowsManager::show_message_box handler in C++ backend"""
