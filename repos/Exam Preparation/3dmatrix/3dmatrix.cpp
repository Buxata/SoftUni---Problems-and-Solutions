#include <iostream>
#include <random>

const int SIZE_ARR = 3;

// *** ONLY FOR SHOWING MEMORY ***

void printReservedMemory(char arr[SIZE_ARR][SIZE_ARR][SIZE_ARR]) {
    std::cout << "\n";
    std::cout << "---------------------------------------" << std::endl;
    std::cout << " bot             | side                " << std::endl;
    std::cout << "                 |                     " << std::endl;
    std::cout << "     " << arr[0][0][0] << " " << arr[0][1][0] << " " << arr[0][2][0] << "       |     " << arr[2][2][2] << " " << arr[1][2][2] << " " << arr[0][2][2] << "           " << std::endl;
    std::cout << "     " << arr[1][0][0] << " " << arr[1][1][0] << " " << arr[1][2][0] << "       |     " << arr[2][2][1] << " " << arr[1][2][1] << " " << arr[0][2][1] << "           " << std::endl;
    std::cout << "     " << arr[2][0][0] << " " << arr[2][1][0] << " " << arr[2][2][0] << "       |     " << arr[2][2][0] << " " << arr[1][2][0] << " " << arr[0][2][0] << "           " << std::endl;
    std::cout << "                 |                     " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << " front           |3D    " << arr[0][0][2] << "              " << std::endl;
    std::cout << "                 |    " << arr[1][0][2] << " " << arr[0][0][1] << "     " << arr[0][1][2] << "        " << std::endl;
    std::cout << "     " << arr[2][0][2] << " " << arr[2][1][2] << " " << arr[2][2][2] << "       |  " << arr[2][0][2] << " " << arr[1][0][1] << " " << arr[0][0][0] << "   " << arr[1][1][2] << " " << arr[0][1][1] << "     " << arr[0][2][2] << "  " << std::endl;
    std::cout << "     " << arr[2][0][1] << " " << arr[2][1][1] << " " << arr[2][2][1] << "       |  " << arr[2][0][1] << " " << arr[1][0][0] << "   " << arr[2][1][2] << " " << arr[1][1][1] << " " << arr[0][1][0] << "   " << arr[1][2][2] << " " << arr[0][2][1] << " " << std::endl;
    std::cout << "     " << arr[2][0][0] << " " << arr[2][1][0] << " " << arr[2][2][0] << "       |  " << arr[2][0][0] << "     " << arr[2][1][1] << " " << arr[1][1][0] << "   " << arr[2][2][2] << " " << arr[1][2][1] << " " << arr[0][2][0] << "  " << std::endl;
    std::cout << "                 |        " << arr[2][1][0] << "     " << arr[2][2][1] << " " << arr[1][2][0] << "    " << std::endl;
    std::cout << "                 |              " << arr[2][2][0] << "    " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
}

void stepsOfReservedMemory() {
    char arr[SIZE_ARR][SIZE_ARR][SIZE_ARR]{
        {{'.','.','.'}, {'.','.','.'}, {'.','.','.'}},
        {{'.','.','.'}, {'.','.','.'}, {'.','.','.'}},
        {{'.','.','.'}, {'.','.','.'}, {'.','.','.'}},
    };
    std::cout << "\nVisualization of empty 3D matrix:";
    printReservedMemory(arr);
    std::cout << "\nReserved memory for 3 x 2D pointers: int*** arr3D = new int** [SIZE_ARR] {};";
    for (int i = 0; i < SIZE_ARR; ++i) {
        arr[i][0][0] = 'R';
    }
    printReservedMemory(arr);
    std::cout << "\nIn each 2D pointers reserved memory for 3 x 1D pointers: arr3D[i] = new int* [SIZE_ARR] {};";
    for (int i = 0; i < SIZE_ARR; ++i) {
        for (int j = 0; j < SIZE_ARR; ++j) {
            arr[i][j][0] = 'R';
        }
    }
    printReservedMemory(arr);
    std::cout << "\nIn each 1D pointers reserved memory for 3 x int pointers: arr3D[i][j] = new int[SIZE_ARR] {};";
    for (int i = 0; i < SIZE_ARR; ++i) {
        for (int j = 0; j < SIZE_ARR; ++j) {
            for (int k = 0; k < SIZE_ARR; ++k) {
                arr[i][j][k] = 'R';
            }
        }
    }
    printReservedMemory(arr);
}

// *** THE CODE ***

int*** createMatrix() {

    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> randomNum(0, 9);

    int*** arr3D = new int** [SIZE_ARR] {}; // for 3 pointers -> 2D
    for (int i = 0; i < SIZE_ARR; ++i) {

        arr3D[i] = new int* [SIZE_ARR] {};  // for 3 x 3 pointers -> 1D
        for (int j = 0; j < SIZE_ARR; ++j) {

            arr3D[i][j] = new int[SIZE_ARR] {}; // for each 1D pointer
            for (int k = 0; k < SIZE_ARR; ++k) {
                arr3D[i][j][k] = randomNum(gen);
            }
        }
    }
    return arr3D;
}

void releaseMemory(int***& arr3D) {
    for (int i = 0; i < SIZE_ARR; ++i) {
        for (int j = 0; j < SIZE_ARR; ++j) {
            delete[] arr3D[i][j]; // delete 1D arrays
            arr3D[i][j] = nullptr;
        }
        delete[] arr3D[i]; // delete 3 x 2D array
        arr3D[i] = nullptr;
    }
    delete[] arr3D; // delete the 3D array
    arr3D = nullptr;
}

int sumOfMatrix3d(int***& arr3D) {
    int sum = 0;
    for (int i = 0; i < SIZE_ARR; ++i) {
        for (int j = 0; j < SIZE_ARR; ++j) {
            for (int k = 0; k < SIZE_ARR; ++k) {
                sum += arr3D[i][j][k];
            }
        }
    }
    return sum;
}

void printVisualization(int***& arr) {
    std::cout << "\nThe 3D matrix:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << " bot             | side                " << std::endl;
    std::cout << "                 |                     " << std::endl;
    std::cout << "     " << arr[0][0][0] << " " << arr[0][1][0] << " " << arr[0][2][0] << "       |     " << arr[2][2][2] << " " << arr[1][2][2] << " " << arr[0][2][2] << "           " << std::endl;
    std::cout << "     " << arr[1][0][0] << " " << arr[1][1][0] << " " << arr[1][2][0] << "       |     " << arr[2][2][1] << " " << arr[1][2][1] << " " << arr[0][2][1] << "           " << std::endl;
    std::cout << "     " << arr[2][0][0] << " " << arr[2][1][0] << " " << arr[2][2][0] << "       |     " << arr[2][2][0] << " " << arr[1][2][0] << " " << arr[0][2][0] << "           " << std::endl;
    std::cout << "                 |                     " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << " front           |3D    " << arr[0][0][2] << "              " << std::endl;
    std::cout << "                 |    " << arr[1][0][2] << " " << arr[0][0][1] << "     " << arr[0][1][2] << "        " << std::endl;
    std::cout << "     " << arr[2][0][2] << " " << arr[2][1][2] << " " << arr[2][2][2] << "       |  " << arr[2][0][2] << " " << arr[1][0][1] << " " << arr[0][0][0] << "   " << arr[1][1][2] << " " << arr[0][1][1] << "     " << arr[0][2][2] << "  " << std::endl;
    std::cout << "     " << arr[2][0][1] << " " << arr[2][1][1] << " " << arr[2][2][1] << "       |  " << arr[2][0][1] << " " << arr[1][0][0] << "   " << arr[2][1][2] << " " << arr[1][1][1] << " " << arr[0][1][0] << "   " << arr[1][2][2] << " " << arr[0][2][1] << " " << std::endl;
    std::cout << "     " << arr[2][0][0] << " " << arr[2][1][0] << " " << arr[2][2][0] << "       |  " << arr[2][0][0] << "     " << arr[2][1][1] << " " << arr[1][1][0] << "   " << arr[2][2][2] << " " << arr[1][2][1] << " " << arr[0][2][0] << "  " << std::endl;
    std::cout << "                 |        " << arr[2][1][0] << "     " << arr[2][2][1] << " " << arr[1][2][0] << "    " << std::endl;
    std::cout << "                 |              " << arr[2][2][0] << "    " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
}


int main()
{
    // only for showing memory
    stepsOfReservedMemory();

    // the code
    int*** arr3D = createMatrix();

    printVisualization(arr3D);

    std::cout << "Sum of the elements: " << sumOfMatrix3d(arr3D) << std::endl;

    releaseMemory(arr3D);

    return 0;
}