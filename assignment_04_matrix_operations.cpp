// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Maximum allowed size for the square storage arrays (per assignment spec)
const int MAX = 10;

// -----------------------------------------------------------------------------
// Helper: readMatrix
// Reads an rows x cols matrix from the user, one element at a time.
// -----------------------------------------------------------------------------
void readMatrix(int mat[MAX][MAX], int rows, int cols, const string& name) {
    cout << "\n--- Entering Matrix " << name << " ---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// Helper: displayMatrix
// Displays a rows x cols matrix in a neat, aligned grid using setw().
// -----------------------------------------------------------------------------
void displayMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
void transposeMatrix() {
    cout << "\n======== PART A: Transpose a Matrix ========" << endl;

    int M, N;
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    // Read the original M x N matrix
    int mat[MAX][MAX];
    readMatrix(mat, M, N, "A");

    // Compute the transpose (will be N x M)
    int trans[MAX][MAX];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    // Display the original matrix
    cout << "\nOriginal Matrix (" << M << " x " << N << "):" << endl;
    displayMatrix(mat, M, N);

    // Display the transposed matrix
    cout << "\nTransposed Matrix (" << N << " x " << M << "):" << endl;
    displayMatrix(trans, N, M);
}

// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
void addMatrices() {
    cout << "\n======== PART B: Add Two Matrices ========" << endl;

    int M, N;
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    // Read both matrices (must be the same size M x N)
    int matA[MAX][MAX];
    int matB[MAX][MAX];
    readMatrix(matA, M, N, "A");
    readMatrix(matB, M, N, "B");

    // Compute the element-wise sum
    int sum[MAX][MAX];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    // Display all three matrices
    cout << "\nMatrix A:" << endl;
    displayMatrix(matA, M, N);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matB, M, N);

    cout << "\nSum (A + B):" << endl;
    displayMatrix(sum, M, N);
}

// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices() {
    cout << "\n======== PART C: Multiply Two Matrices ========" << endl;

    // --- Read Matrix A (M x N) ---
    int M, N;
    cout << "\n--- Matrix A ---" << endl;
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    int matA[MAX][MAX];
    readMatrix(matA, M, N, "A");

    // --- Read Matrix B (N x P) ---
    // Number of rows in B must equal number of columns in A (N)
    int P;
    int rowsB;
    int matB[MAX][MAX];
    cout << "\n--- Matrix B ---" << endl;

    while (true) {
        cout << "Enter number of rows: ";
        cin >> rowsB;
        if (rowsB != N) {
            cout << "ERROR: Number of rows in B must equal number of "
                 << "columns in A (" << N << "). Please try again." << endl;
        } else {
            break;
        }
    }
    cout << "Enter number of columns: ";
    cin >> P;

    readMatrix(matB, N, P, "B");

    // --- Compute the product A x B (result is M x P) ---
    int prod[MAX][MAX];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < N; k++) {
                prod[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    // --- Display all three matrices ---
    cout << "\nMatrix A (" << M << " x " << N << "):" << endl;
    displayMatrix(matA, M, N);

    cout << "\nMatrix B (" << N << " x " << P << "):" << endl;
    displayMatrix(matB, N, P);

    cout << "\nProduct (A x B) -> Result (" << M << " x " << P << "):" << endl;
    displayMatrix(prod, M, P);
}

// -----------------------------------------------------------------------------
// main — runs all three parts
// -----------------------------------------------------------------------------
int main() {
    cout << "================================================" << endl;
    cout << "        MATRIX OPERATIONS PROGRAM" << endl;
    cout << "================================================" << endl;

    transposeMatrix();
    addMatrices();
    multiplyMatrices();

    cout << "\n================================================" << endl;
    cout << "        All operations completed. Goodbye!" << endl;
    cout << "================================================" << endl;

    return 0;
}

