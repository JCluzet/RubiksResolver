
# Rubik's Cube Solver and Visualizer

This project offers a comprehensive solution for solving and visualizing 3x3x3 Rubik's Cubes. It accepts a predefined mix sequence as input and provides the solving sequence, adhering strictly to the standard Rubik's Cube notation (F R U B L D). The project is structured to ensure a user-friendly experience with an average solution time within 3 seconds and an average spin count of 50 moves.

## Getting Started

### Prerequisites

- Python 3.x for the visualizer
- C++ compiler for the solver

### Installation

1. Clone the repository:
```bash
git clone https://your-repo-url.git
```

2. Install Python dependencies for the visualizer:
```bash
cd Visualizer
pip install -r requirements.txt
```

3. Compile the solver:
```bash
cd ../resolver
make
```

## Usage

To solve and visualize a Rubik's Cube mix, run the solver with the mix sequence as an argument:

```bash
./resolver/rubik "F R U2 B' L' D'"
```

The solution will be output to the console, and the moves will be written to `Visualizer/moves.txt`.

To visualize the solution, run the visualizer:

```bash
python Visualizer/rubik.py
```

## Contributing

Contributions to the project are welcome! Please refer to the CONTRIBUTING.md for more details.

## Credits

This project was developed in collaboration with [sdesseau](https://github.com/sdesseau).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- FrancoCube for Rubik's Cube notation and solving strategies.
- The 42 School community for project inspiration and support.
