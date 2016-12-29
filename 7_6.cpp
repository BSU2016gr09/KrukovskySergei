#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
    В матрице (m,n) удалить нулевые строки
*/
const int NUMBER_LINE = 5;//количество строк в матрице
const int NUMBER_COLUM = 7;//количество столбцов в матрице

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//проверят находится ли максимальный элемент в строке на первом месте
bool checkLineOnMax(int arr[], int length);
//печатает матрицу(для того что бы пичалось конкретное число строк и столбцов матрицы)
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM], int numLine, int numColum);
//удаление строк где максимальный элемент стоит на первом месте
void deleteMaxLinesFromMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//нахождение максимума в строке
int searchMaxInLine(int arr[], int lenght);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    cout<<endl<<endl<<endl<<endl<<endl;
    deleteMaxLinesFromMatrix(matrix);

    return 0;
}

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){

    for(int i=0; i<NUMBER_LINE; i++){
        for(int j=0; j<NUMBER_COLUM; j++){
            cout<<matrix[i][j]<<"     ";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }

}

//печатает матрицу(для того что бы пичалось конкретное число строк и столбцов матрицы)
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM], int numLine, int numColum){

    for(int i=0; i<numLine; i++){
        for(int j=0; j<numColum; j++){
            cout<<matrix[i][j]<<"     ";
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }

}

//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    srand ( time(NULL) );
    for(int i=0; i<NUMBER_LINE; i++){
        for(int j=0; j<NUMBER_COLUM; j++){
            matrix[i][j] = rand()%10;
        }

    }
}
//проверят находится ли максимальный элемент в строке на первом месте
bool checkLineOnMax(int arr[], int length){

    bool result = true;
    int maxElement = searchMaxInLine(arr, length);
    if(arr[0] != maxElement){
            result = false;
    }

    return result;
}

//нахождение максимума в строке
int searchMaxInLine(int arr[], int lenght){

    int result = arr[0];
    for(int i=1; i<lenght; i++){
        if(result < arr[i]){
            result = arr[i];
        }
    }
    return result;

}

//удаление строк где максимальный элемент стоит на первом месте
void deleteMaxLinesFromMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){

    int numLine = 0;
    int numColum = NUMBER_COLUM;
    int i = 0;
    int countLine = NUMBER_LINE;
    while(countLine){
            if(checkLineOnMax(matrix[i], NUMBER_COLUM)){
                for(int q=i; q<NUMBER_LINE-1; q++){
                    for(int j = 0; j < NUMBER_COLUM; j++){
                        matrix[q][j] = matrix[q+1][j];
                    }
                }
                countLine--;
                continue;
            }
            i++;
            numLine++;
            countLine--;
    }

    printMatrix(matrix, numLine, numColum);

}


