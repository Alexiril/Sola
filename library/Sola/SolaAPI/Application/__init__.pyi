"""@package Sola.SolaAPI.Application
This module is just a type definition for the Sola Python API Application.
"""

from typing import Any

def isAppEditor() -> bool:
    """Returns True if the application is editor, false otherwise."""

def getProjectDir() -> str:
    """Returns the current opened project directory"""

def getAppName() -> str:
    """Returns the application name"""

def getAppVersion() -> str:
    """Returns the application version"""

def getAppIdentifier() -> str:
    """Returns the application identifier"""

def getAppCreator() -> str:
    """Returns the application creator"""

def getAppCopyright() -> str:
    """Returns the application copyright"""

def getAppUrl() -> str:
    """Returns the application url"""

def getProjectConfiguration() -> dict[str, Any]:
    """Returns the current project configuration data"""

def setProjectConfiguraiton(Config: dict[str, Any]) -> None:
    """Stores actual project configuration in C++ backend"""
