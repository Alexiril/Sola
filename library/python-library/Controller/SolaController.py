from abc import ABCMeta, abstractmethod
from typing import Any


class SolaController(metaclass=ABCMeta):

    __slots__ = []

    @abstractmethod
    def __init__(self, settings: dict[str, Any]) -> None: ...

    @abstractmethod
    def start(self) -> None: ...


__all__ = ["SolaController"]
