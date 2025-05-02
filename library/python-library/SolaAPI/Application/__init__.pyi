from typing import Any

def is_app_editor() -> bool:
    """Returns True if the application is editor, false otherwise."""

def get_project_dir() -> str:
    """Returns the current opened project directory"""

def get_app_name() -> str:
    """Returns the application name"""

def get_app_version() -> str:
    """Returns the application version"""

def get_app_identifier() -> str:
    """Returns the application identifier"""

def get_app_creator() -> str:
    """Returns the application creator"""

def get_app_copyright() -> str:
    """Returns the application copyright"""

def get_app_url() -> str:
    """Returns the application url"""

def get_project_configuration() -> dict[str, Any]:
    """Returns the current project configuration data"""

def set_project_configuration(config: dict[str, Any]) -> None:
    """Stores actual project configuration in C++ backend"""
