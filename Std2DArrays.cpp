
#include "Std2DArrays.h"
#include <iostream>
#include <algorithm>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int value = 1;

    // Fill the array from NE corner diagonally down (NE DIAG DOWN)
    for (int diag = 0; diag < rows + columns - 1; diag++) {
        int row = std::max(0, diag - columns + 1); // Start from the correct row
        int col = std::min(diag, columns - 1);      // Start from the correct column

        while (row < rows && col >= 0) {
            arr[row][col] = value;
            value++;
            row++;
            col--;
        }
    }
}

void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
