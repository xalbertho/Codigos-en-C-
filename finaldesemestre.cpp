//no hice la tarea pipipipipipipipipipi

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


using namespace std;

const int NUM_LETTERS = 80;
const int NUM_ROWS = 25;

char getRandomCharacter(const string& characters) {
    int index = rand() % characters.length();
    return characters[index];
}

void printMatrixRain(const string& characters) {
    string matrix[NUM_ROWS][NUM_LETTERS];
    int columnCount[NUM_LETTERS] = {0};

    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        system("cls");


        for (int i = 0; i < NUM_LETTERS; i++) {
            if (columnCount[i] < NUM_ROWS) {
                matrix[columnCount[i]][i] = getRandomCharacter(characters);
                columnCount[i]++;
            } else {
                if (rand() % 100 < 5) {
                    matrix[0][i] = getRandomCharacter(characters);
                } else {
                    matrix[0][i] = ' ';
                }
            }
        }

        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_LETTERS; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
        Sleep(100);

    }
}

int main() {
    string characters;

    cout << "Ingrese los caracteres que desea que caigan: ";
    getline(cin, characters);

    printMatrixRain(characters);

    return 0;
}









