# Tic-Tac-Toe

This is a Tic-Tac-Toe game implemented in C, featuring a Minimax Algorithm for decision-making.

## Project Structure

- **`build/`**: Directory for build artifacts (object files and executable).
- **`include/`**: Directory for header files.
- **`src/`**: Directory for source files.
- **`Makefile`**: Build script to compile the project.
- **`README.md`**: Project documentation.

## Building the Project

To build the project, follow these steps:

1. **Navigate to the project directory**:
    ```sh
    cd /path/to/your/project
    ```

2. **Run the `make` command**:
    ```sh
    make
    ```

    This will compile the source files and generate the executable in the `build/` directory.

## Running the Game

To run the Tic-Tac-Toe game after building, execute the appropriate command based on your operating system:

- **On Linux**:
    ```sh
    ./build/main
    ```

- **On Windows**:
    ```sh
    .\build\main.exe
    ```

## Notes

- Ensure you have a compatible C compiler and `make` utility installed on your system.
- For more details on the Minimax Algorithm and game mechanics, refer to the source code in the `src/` directory.
