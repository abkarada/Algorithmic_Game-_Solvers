# 🧩 Algorithmic Game Solvers

This repository is dedicated to solving **constraint-based logic games** using algorithmic strategies implemented in **pure C**.  
The main goal is to explore how game-like puzzles can be solved with **custom backtracking, pruning, and heuristic methods**, without relying on any external libraries or engines.

---

## 🎯 Featured Solver: Skyscraper Puzzle

### 🏙️ What is the Skyscraper Puzzle?

The **Skyscraper Puzzle** is a logic game similar to Sudoku, but with an additional visibility constraint:  
Each cell in an `n x n` grid represents a building of height 1 to `n`, and numbers around the edges indicate how many buildings are visible from that direction (taller buildings obscure the view of shorter ones behind them).

### 🔧 Example Input Format


Top:    [2 1 3 2]
Bottom: [2 3 1 2]
Left:   [1 2 2 3]
Right:  [2 2 3 1]

🛠 Implementation Details
Language: C (100%)

Algorithm: Backtracking search with constraint propagation

Validation: Ensures row/column uniqueness and visibility constraints

Structure:

Grid representation as 2D matrix

Recursive solver with rollback mechanism

Input/output parser and result visualizer

Algorithmic_Game_Solvers/
└── Skyscraper_Puzzle_Solver/
    ├── skyscraper_solver.c      # Core solver logic
    ├── puzzle_input.txt         # Sample input
    └── output_grid.txt          # Solved puzzle output (optional)

gcc Skyscraper_Puzzle_Solver/skyscraper_solver.c -o skyscraper_solver

./skyscraper_solver

Solved Grid (4x4):
[ 2 1 4 3 ]
[ 3 4 1 2 ]
[ 1 2 3 4 ]
[ 4 3 2 1 ]
✅ Constraints respected (row/column uniqueness and visibility rules)

🧠 Why C?
This project is an exercise in bare-metal logic implementation.
No STL, no fancy object-oriented abstractions — just pure, deterministic logic and memory management.

This approach is perfect for:

Algorithmic thinking

Constraint satisfaction problems (CSP)

Memory-aware recursive search

🔮 Future Additions
 N-Queens Solver

 Kakuro Puzzle Solver

 Sudoku Solver (Advanced version with dancing links)

 GUI/CLI visualizer with SDL or ncurses (optional)

🤝 Contributions
If you’re into algorithms, game theory, or logic puzzle solving — feel free to contribute other games, solvers, or performance improvements.

📜 License
This project is released under the MIT License.

🧠 "A puzzle is not just a challenge. It’s a structured simulation of logic itself." 
