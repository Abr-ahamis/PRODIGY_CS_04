import os
import subprocess
import sys

def run_command(command):
    """Run a shell command and handle errors."""
    try:
        subprocess.run(["bash", "-c", command], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")
        sys.exit(1)

def main():
    # Define the path for the virtual environment
    env_path = os.path.join(os.getcwd(), "env")
    activate_env = f"source {env_path}/bin/activate"

    print("Setting up the virtual environment and installing dependencies...")

    # Create virtual environment if it doesn't exist
    if not os.path.exists(env_path):
        print("Creating virtual environment...")
        run_command(f"python3 -m venv {env_path}")

    # Upgrade pip and install dependencies within the virtual environment
    print("Upgrading pip and installing required packages...")
    run_command(f"{activate_env} && python -m pip install --upgrade pip && python -m pip install pynput")

    print("Setup completed successfully!")

if __name__ == "__main__":
    main()
