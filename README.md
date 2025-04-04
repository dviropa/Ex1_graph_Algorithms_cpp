# Graph Assignment - Adjacency List Implementation

**Author:** Dvir  
**Email:** dvir.opa@gmail.com


## Overview

This project implements an undirected weighted graph using an **adjacency list** structure without using the C++ Standard Template Library (STL).  
The goal is to demonstrate understanding of core C++ concepts such as:

- Manual memory management
- Classes, constructors, destructors
- Object passing and returning
- Namespaces
- Exception handling
- Custom data structures (Queue, Stack, Union-Find)

## Structure

The project is organized into several modules:

### Core Classes

- `Graph` – the main class representing the graph. Holds an adjacency list internally (`adesenlist`).
- `Edge` – represents an edge with source, destination, and weight.
- `auterNode` – represents a vertex and its neighbor list.
- `inerNode` – represents an edge inside a vertex's adjacency list.
- `adesenlist` – manages the list of vertices and their connections.

### Algorithms

- `Algorithms` class implements:
    - BFS 
    - DFS 
    - Dijkstra 
    - Prim 
    - Kruskal 

### Data Structures

- `Queue`  
- `Stack` 
- `UnionFind` 

## Features

-  Add/remove undirected weighted edges
-  Get neighbors and weights
-  Print graph
-  Generate BFS / DFS trees
-  Generate MST (Prim, Kruskal)
-  Run Dijkstra and return shortest paths tree
-  Validate only positive weights for Dijkstra
-  Equality operators for comparing graphs
-  Unit tests with `doctest`
-  Memory-safe (checked with `valgrind`)

## How to Run

### Compilation (Using Makefile)

```bash
make run       # Compiles and runs main.cpp
make testAlgo       # Runs tests on Algorithms 
    and then ./testGraph
make testGraph       # Runs tests on Graph
    and then ./testAlgo
make valgrind   # Checks memory leaks
make clean      # Cleans build files
