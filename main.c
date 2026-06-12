
#include <stdio.h>

/*
 * Iteration 0: Adjacency Logic
 *
 * Geometry should be calculated, not stored. By leveraging bit-shifting 
 * and XOR to calculate Hamming distance, the adjacency of two vertices 
 * is determined on the fly.
 */

// Determines if two vertices are connected in an N-dimensional hypercube.
// Two vertices are connected if they differ by exactly one bit.
// IMPORTANT NOTE: This engine currently utilizes Hamming distance adjacency,
// which strictly maps to N-dimensional hypercube (orthotope) topology. Future 
// iterations may explore affine transformations or non-orthogonal basis sets 
// to support broader manifold types.
int is_connected(int a, int b) {
    int diff = a ^ b;
    // Returns true if diff is a power of 2 (exactly one bit set).
    /*
    int prod = 1;
    for(int i=0; i<4; i++){
        if(diff == prod){
            return true;
        }
        prod *= 2;
    }
    return false;
    */
    // Removes need to loop or perform artithmetic 
    return (diff != 0) && ((diff & (diff - 1)) == 0);
}

// Projects a bit-pattern vertex into N-dimensional Euclidean space
void get_vertex_coords(int vertex, int dimensions, float* output) {
    for (int i = 0; i < dimensions; i++) {
        // If the i-th bit is set, the vertex is at +1 in that dimension
        output[i] = (vertex & (1 << i)) ? 1.0f : -1.0f;
    }
}

int main() {
    printf("--- Iteration 0: Adjacency Test ---\n");
    
    // Testing connectivity for a 4D Tesseract (0 to 15)
    for (int i = 0; i < 16; i++) {
        printf("Vertex %d connects to: ", i);
        for (int j = 0; j < 16; j++) {
            if (is_connected(i, j)) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    
    return 0;
}
