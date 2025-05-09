"""@package Sola.SolaAPI.Graphics
This module is just a type definition for the Sola Python API Graphics.
"""

from collections.abc import Callable
from typing import Literal

class ButtonData:
    """Class representing a button in a message box."""

    def __init__(self, button_id: int, is_escape_default: bool, is_enter_default: bool, text: str) -> None:
        """Initialize a button with the given parameters.
        Args:
            button_id (int): The ID of the button.
            is_escape_default (bool): Whether this button is the default escape button.
            is_enter_default (bool): Whether this button is the default enter button.
            text (str): The text to display on the button.
        """

def show_message_box(
    severity: Literal["none", "info", "warning", "error"],
    title: str,
    message: str,
    buttons: list[ButtonData],
    callback: Callable[[int], None],
) -> None:
    """Calls WindowsManager::show_message_box handler in C++ backend"""
