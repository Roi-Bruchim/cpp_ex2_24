# EX2: Graph Operations

## Overview
This assignment extends the EX1 assignment by adding operators to a graph represented by an adjacency matrix. Each operator ensures that the given graphs satisfy the requirements of the operator. Each operator and helper function has several tests to check their correctness. There is a demo that you can run by executing the command `./demo` to see the operators and how they affect the algorithms we implemented in the last assignment.

## Operators

### Arithmetic Operators
- `+`: Creates a new graph with the size of the two given graphs. Each cell of the new graph is the sum of the corresponding cells of the input graphs: `g3[i][j] = g1[i][j] + g2[i][j]`.
- `+=`: Adds the values of the corresponding cells of another graph to the current graph: `g1[i][j] += g2[i][j]`.
- Unary `+`: Returns a new graph that is a copy of the current graph.
- `-`: Creates a new graph with the size of the two given graphs. Each cell of the new graph is the difference of the corresponding cells of the input graphs: `g3[i][j] = g1[i][j] - g2[i][j]`.
- `-=`: Subtracts the values of the corresponding cells of another graph from the current graph: `g1[i][j] -= g2[i][j]`.
- Unary `-`: Returns a new graph where each cell of the current graph is multiplied by -1.
- `++`: Increments each edge value in the graph by 1 (only for edges, i.e., cells that are not zero).
- `--`: Decrements each edge value in the graph by 1 (only for edges, i.e., cells that are not zero).
- `*` (with scalar): Multiplies each cell of the graph by a given scalar: `g[i][j] *= scalar`.
- `*` (two graphs): Multiplies two graphs using matrix multiplication. For more information, see [Matrix Multiplication](https://en.wikipedia.org/wiki/Matrix_multiplication).

### Comparison Operators
- `==`: Compares two graphs to ensure they are the same size, have the same edges, and the edges have the same weights.
- `!=`: Returns true if the `==` operator returns false, indicating the graphs are not equal.
- `<=`, `>=`: Use helper methods to check if one graph is a subgraph of another and a counter for the graph edges to determine which graph is greater.

### Output
- `<<`: Prints the graph using `cout`. The graph is displayed as a 2D adjacency matrix.
