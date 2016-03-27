#include <iostream>
#include <vector>
#include <cassert>
void rotate(std::vector<std::vector<int>> &matrix, bool direction = true) {
    // True = Anti clockwise
    // False = Clockwise
    assert(matrix.size() && matrix.size() == matrix[0].size());
    int col_i, row_i, col_d, row_d;
    auto n = matrix.size() - 1;
    auto layers = matrix.size() / 2;
    // Time complexity analysis : theta(n^2)
    for (size_t i = 0; i < layers; i++) {
        for (size_t j = i; j < n - i; j++) {
            // Now, place the elements where you desire
            if (!direction) {
                col_i = matrix[i][j];
                row_i = matrix[j][n - i];
                col_d = matrix[n - i][n - j];
                row_d = matrix[n - j][i];
                matrix[i][j] = row_d;
                matrix[j][n - i] = col_i;
                matrix[n - i][n - j] = row_i;
                matrix[n - j][i] = col_d;
            } else {
                // Anticlockwise rotation --> Problem
                col_d = matrix[i][n - j];
                row_i = matrix[j][i];
                col_i = matrix[n - i][j];
                row_d = matrix[n - j][n - i];
                matrix[j][i] = col_d;
                matrix[n - i][j] = row_i;
                matrix[n - j][n - i] = col_i;
                matrix[i][n - j] = row_d;
            }
        }
    }
}
int main() {
    std::vector<std::vector<int>> mat(4);
    for (auto &row : mat) {
        row = std::vector<int>(4);
    }
    for (size_t i = 0; i < 4; i++) {
        for (size_t k = 0; k < 4; k++) {
            mat[i][k] = (i + 1) * (k + 1);
        }
    }
    for (auto &row : mat) {
        for (auto elem : row) {
            std::cout << elem << " : ";
        }
        std::cout << std::endl;
    }
    std::cout << " - \n";
    rotate(mat);
    for (auto &row : mat) {
        for (auto elem : row) {
            std::cout << elem << " : ";
        }
        std::cout << std::endl;
    }
}
