#!/bin/bash

# Create a virtual environment if it doesn't already exist
if [ ! -d "env" ]; then
    echo "Creating virtual environment..."
    python3 -m venv env
else
    echo "Virtual environment already exists."
fi

# Activate the virtual environment
echo "Activating virtual environment..."
source env/bin/activate

# Install pynput
echo "Installing pynput..."
pip install pynput

# Confirm installation
echo "pynput installed successfully."

# Confirm activation and installation
echo "You are now in the virtual environment (env) with pynput installed."
