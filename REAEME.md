# manifold-bytes

A C-based engine for N-dimensional manifold generation using bitwise logic.

This repository serves as an engineering journal, documenting the evolution of a procedural geometry engine. The objective is to evolve from initial brute-force prototypes into a lean, memory-efficient library that generates geometry on-the-fly using bitwise primitives.

## Philosophy
Geometry should be calculated, not stored. By leveraging bit-shifting and XOR the adjacency of two vertices is determined on the fly when calculating Hamming distance, and N-dimensional shapes can be calculate with near-zero memory footprint.

## Mathematical Basis
This engine utilizes the isomorphism between the N-dimensional hypercube (measure polytope) and the Hamming graph. By leveraging the bitwise Hamming distance for adjacency, the system achieves $O(1)$ connectivity verification, enabling real-time manipulation of high-dimensional lattices without the memory overhead of traditional adjacency matrices.

## Current Roadmap
- [x] **Iteration 0**: Porting Arduino-based bitwise adjacency logic to C.
- [ ] **Iteration 1**: Eliminating redundant vertex buffers and expanding core logic.
- [ ] **Iteration 2**: Implementing procedural rotational projection math.
- [ ] **Iteration 3**: Profiling, refining algorithms, and finalizing optimaizaions.

