from collections.abc import Callable
from typing import Literal

class ButtonData:
    def __init__(self, button_id: int, is_escape_default: bool, is_enter_default: bool, text: str) -> None: ...

def show_message_box(
    severity: Literal["none", "info", "warning", "error"],
    title: str,
    message: str,
    buttons: list[ButtonData],
    callback: Callable[[int], None],
) -> None:
    """Calls WindowsManager::show_message_box handler in C++ backend"""
