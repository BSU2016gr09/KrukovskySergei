#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
    Найти в случайной матрице минимум в каждом столбце
*/
const int NUMBER_LINE = 3;//количество строк в матрице
const int NUMBER_COLUM = 3;//количество столбцов в матрице

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//нахождение минимума в каждом столбце матрицы
int* searchMinInEachColumMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//вывод массива
void printArray(int arr[], int lenght);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    int *result;
    result = searchMinInEachColumMatrix(matrix);
    printArray(result, NUMBER_COLUM);

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

//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    srand ( time(NULL) );
    for(int i=0; i<NUMBER_LINE; i++){
        for(int j=0; j<NUMBER_COLUM; j++){
            matrix[i][j] = rand()%10;
        }

    }
}
//нахождение минимума в каждом столбце матрицы
int* searchMinInEachColumMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    int *result;//здесь храниться минимальные значение каждого столбца..индекл в массиве это номер столбца+1(т.к. все начинается с 0)
    result = new int[NUMBER_COLUM];
    for(int i = 0; i<NUMBER_COLUM; i++){//цикл проходит по каждому столбцу
         int localMin = matrix[0][i];//хранится текущий минимальный элемент в столбце
         for(int j = 1; j < NUMBER_LINE; j++){//цикл проходит по каждой строке
            if(matrix[j][i] < localMin){//если находится элемент меньше то перезаписываем его
                localMin = matrix[j][i];
            }
         }
         result[i] = localMin;
    }
    return result;//возвращается массив элементов
}
//вывод массива
void printArray(int arr[], int lenght){
    int i = 0;
    while(i<lenght){
        cout<<i+1<<"->"<<arr[i]<<endl;
        i++;
    }
}
