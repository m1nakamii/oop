#include <cstdlib> // For generating random numbers
#include <iostream>

class Matrix {
private:
  int **data; // Pointer to the matrix data
  int rows;   // Number of rows
  int cols;   // Number of columns
  int sum;    // Sum of elements

public:
  // Default constructor
  Matrix() : rows(0), cols(0), data(nullptr), sum(0) {}

  // Constructor for creating a square matrix of given dimension
  Matrix(int dimension) : rows(dimension), cols(dimension), sum(0) {
    data = new int *[rows];
    for (int i = 0; i < rows; ++i) {
      data[i] = new int[cols];
      for (int j = 0; j < cols; ++j)
        data[i][j] = (i == j) ? 1 : 0; // Identity matrix
    }
  }

  // Constructor for creating a matrix of given dimensions
  Matrix(int rows, int cols) : rows(rows), cols(cols), sum(0) {
    data = new int *[rows];
    for (int i = 0; i < rows; ++i) {
      data[i] = new int[cols];
      for (int j = 0; j < cols; ++j)
        data[i][j] = 0;
    }
  }

  // Destructor to free dynamically allocated memory
  ~Matrix() {
    for (int i = 0; i < rows; ++i)
      delete[] data[i];
    delete[] data;
  }

  // Function to access a specific element in the matrix
  int getElement(int row, int col) const { return data[row][col]; }

  // Function to set a specific element in the matrix
  void setElement(int row, int col, int value) { data[row][col] = value; }

  // Function to input matrix values from the keyboard
  void inputMatrix() {
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        std::cout << "Enter element at position [" << i << "][" << j << "]: ";
        std::cin >> data[i][j];
      }
    }
  }

  // Function to fill matrix as an identity matrix
  void fillIdentity() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        data[i][j] = (i == j) ? 1 : 0; // Identity matrix
      }
    }
  }

  // Function to fill matrix with product of row and column indices
  void fillProductIndices() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        data[i][j] = (i + 1) * (j + 1); // Product of row and column indices
      }
    }
  }

  // Function to fill matrix with random values
  void fillRandom() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        data[i][j] = rand() % 100; // Random integer between 0 and 99
      }
    }
  }

  // Function to calculate the sum of matrix elements
  void calculateSum() {
    sum = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        sum += data[i][j];
      }
    }
  }

  // Function to display the matrix
  void displayMatrix() {
    std::cout << "Matrix:\n";
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        std::cout << data[i][j] << "\t";
      }
      std::cout << "\n";
    }
  }

  // Function to display the sum of matrix elements
  void displaySum() { std::cout << "Sum of matrix elements: " << sum << "\n"; }
};

int main() {
  // Create matrices using different constructors
  Matrix M1;       // Default constructor
  Matrix M2(3);    // Constructor with size 3x3
  Matrix M3(3, 4); // Constructor with size 3x4
  Matrix M4(2, 3); // Constructor with size 2x3

  // Display matrices M2, M3, M4
  std::cout << "Matrix M2 (3x3):\n";
  M2.displayMatrix();

  std::cout << "Matrix M3 (3x4):\n";
  M3.displayMatrix();

  std::cout << "Matrix M4 (2x3):\n";
  M4.displayMatrix();

  // Fill M2 with product of row and column indices
  M2.fillProductIndices();
  std::cout
      << "Matrix M2 after filling with product of row and column indices:\n";
  M2.displayMatrix();

  // Fill M3 with random values
  M3.fillRandom();
  std::cout << "Matrix M3 after filling with random values:\n";
  M3.displayMatrix();

  // Input values for M4 from the keyboard
  M4.inputMatrix();
  std::cout << "Matrix M4 after input from keyboard:\n";
  M4.displayMatrix();

  // Calculate and display sum of elements for M3
  M3.calculateSum();
  M3.displaySum();

  return 0;
}