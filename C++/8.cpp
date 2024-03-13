#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat.resize(rows, std::vector<int>(cols, 0));
    }

    // Function to get the number of rows
    int getRows() const {
        return rows;
    }

    // Function to get the number of columns
    int getCols() const {
        return cols;
    }

    // Function to set the value of an element
    void setElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            mat[row][col] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Function to get the value of an element
    int getElement(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return mat[row][col];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Function to perform matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices are not compatible for addition");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Function to perform matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrices are not compatible for multiplication");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Function to perform transpose of the matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.mat[i][j] = mat[j][i];
            }
        }
        return result;
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns for Matrix 1: ";
    std::cin >> rows >> cols;
    Matrix mat1(rows, cols);

    std::cout << "Enter the elements of Matrix 1:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int element;
            std::cin >> element;
            mat1.setElement(i, j, element);
        }
    }

    std::cout << "Enter the number of rows and columns for Matrix 2: ";
    std::cin >> rows >> cols;
    Matrix mat2(rows, cols);

    std::cout << "Enter the elements of Matrix 2:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int element;
            std::cin >> element;
            mat2.setElement(i, j, element);
        }
    }

    char choice;
    std::cout << "\nMenu:" << std::endl;
    std::cout << "a. Sum" << std::endl;
    std::cout << "b. Product" << std::endl;
    std::cout << "c. Transpose" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    try {
        switch (choice) {
            case 'a': {
                if (mat1.getRows() != mat2.getRows() || mat1.getCols() != mat2.getCols()) {
                    throw std::invalid_argument("Matrices are not compatible for addition");
                }
                Matrix sum = mat1 + mat2;
                std::cout << "Sum of the matrices:" << std::endl;
                for (int i = 0; i < sum.getRows(); ++i) {
                    for (int j = 0; j < sum.getCols(); ++j) {
                        std::cout << sum.getElement(i, j) << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            }
            case 'b': {
                Matrix product = mat1 * mat2;
                std::cout << "Product of the matrices:" << std::endl;
                for (int i = 0; i < product.getRows(); ++i) {
                    for (int j = 0; j < product.getCols(); ++j) {
                        std::cout << product.getElement(i, j) << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            }
            case 'c': {
                Matrix transposed = mat1.transpose();
                std::cout << "Transpose of Matrix 1:" << std::endl;
                for (int i = 0; i < transposed.getRows(); ++i) {
                    for (int j = 0; j < transposed.getCols(); ++j) {
                        std::cout << transposed.getElement(i, j) << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
