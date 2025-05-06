def raise_warning(what: str) -> None:
    """
    Raises warning inside C++ backend. Writes the warning to the log.
    Shows simple popup window with the warning text and okay button.
    """

def raise_error(what: str) -> None:
    """
    Raises error inside C++ backend. Writes the error to the log.
    Shows simple popup window with the error text and two choises: ignore or quit.
    """

def raise_fatal(what: str) -> None:
    """
    Raises fatal inside C++ backend. Writes the fatal error to the log.
    Completely stops all the processes in the application, and shows
    simple popup window with the fatal error text and quit button.
    """
