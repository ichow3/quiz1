#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

bool isLoShuMagicSquare(int square[SIZE][SIZE]);
void generateRandomSquare(int square[SIZE][SIZE]);
void printSquare(int square[SIZE][SIZE]);

int main() {
    int square[SIZE][SIZE];
    int count = 0;

    do {
        generateRandomSquare(square);
        count++;
    } while (!isLoShuMagicSquare(square));

 
    printf("Total number of squares generated: %d\n", count);
    printSquare(square);

    return 0;
}

// Function to check if the array is a Lo Shu Magic Square
bool isLoShuMagicSquare(int square[SIZE][SIZE]) {
    int sumRow, sumCol, sumDiagonal1, sumDiagonal2;

    // Check sum of rows
    for (int i = 0; i < SIZE; i++) {
        sumRow = 0;
        sumCol = 0;
        for (int j = 0; j < SIZE; j++) {
            sumRow += square[i][j];
            sumCol += square[j][i];
        }
        if (sumRow != 15 || sumCol != 15) {
            return false;
        }
    }

    sumDiagonal1 = 0;
    sumDiagonal2 = 0;
    for (int i = 0; i < SIZE; i++) {
        sumDiagonal1 += square[i][i];
        sumDiagonal2 += square[i][SIZE - i - 1];
    }

    return sumDiagonal1 == 15 && sumDiagonal2 == 15;
}

void generateRandomSquare(int square[SIZE][SIZE]) {
    int usedNumbers[9] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num;
            do {
                num = rand() % 9 + 1;
            } while (usedNumbers[num - 1]);
            usedNumbers[num - 1] = 1;
            square[i][j] = num;
        }
    }
}

// Function to print the square
void printSquare(int square[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}