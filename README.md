
# Rubik's Cube Solver and Visualizer

This project provides a comprehensive solution for solving and visualizing Rubik's Cube puzzles. It includes a C++ program to solve the cube and a Python script for visualization. This collaborative effort with [sdesseau](https://github.com/sdesseau) offers a practical approach to understanding and solving Rubik's Cube.

## Project Structure

```
.
├── LICENSE
├── Visualizer
│   ├── moves.txt
│   ├── requirements.txt
│   └── rubik.py
└── resolver
    ├── Makefile
    ├── RubiksCube.cpp
    ├── RubiksCube.hpp
    ├── main.cpp
    └── readme.txt
```

3 directories, 9 files

## Getting Started

To use the Rubik's Cube Solver and Visualizer, follow these steps:

### Solver

Navigate to the `resolver/` directory:

```bash
cd resolver/
```

Compile the solver:

```bash
make re
```

Run the solver with a mix sequence as an argument. For example:

```bash
./rubiksCube "F R U2 B' L' D'"
```

### Visualizer

Ensure you have Python 3 installed on your system. Navigate to the `Visualizer/` directory:

```bash
cd Visualizer/
```

Install the required Python packages:

```bash
pip install -r requirements.txt
```

Run the visualizer:

```bash
python3 rubik.py
```

The visualizer will display the Rubik's Cube and animate the solution provided by the solver.

## Contributions

This project is a collaborative effort. Feel free to contribute or suggest improvements by creating issues or pull requests on GitHub.
#### 👋 If you have any problem with the test, it would be nice to create an "Issue", it will take 3 minutes of your time and it will help me to make the test accessible to more people. 
#### Remember that if you encounter an error, you are probably not the only one and your "Issue" will surely help other people.

## Credits

- [sdesseau](https://github.com/sdesseau) for their contributions to this project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
