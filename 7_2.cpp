
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
    Найти в случайной матрице седловую точку
*/
const int NUMBER_LINE = 3;//количество строк в матрице
const int NUMBER_COLUM = 5;//количество столбцов в матрице

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//нахождение максимума в каждом столбце матрицы
int* searchMaxInEachColumMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//вывод массива
void printArray(int arr[], int lenght);
//нахождение минимума в строке
int searchMinInLine(int arr[], int lenght);
//нахождение седловой точки
void getSaddlePoints(int matrix[NUMBER_LINE][NUMBER_COLUM]);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    getSaddlePoints(matrix);
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
//нахождение максимума в каждом столбце матрицы
int* searchMaxInEachColumMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    int *result;//здесь храниться максимальные значение каждого столбца..индекл в массиве это номер столбца+1(т.к. все начинается с 0)
    result = new int[NUMBER_COLUM];
    for(int i = 0; i<NUMBER_COLUM; i++){//цикл проходит по каждому столбцу
         int localMax = matrix[0][i];//хранится текущий минимальный элемент в столбце
         for(int j = 1; j < NUMBER_LINE; j++){//цикл проходит по каждой строке
            if(matrix[j][i] > localMax){//если находится элемент меньше то перезаписываем его
                localMax = matrix[j][i];
            }
         }
         result[i] = localMax;
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
//нахождение минимума в строке
int searchMinInLine(int arr[], int lenght){

    int result = arr[0];
    for(int i=1; i<lenght; i++){
        if(result > arr[i]){
            result = arr[i];
        }
    }
    return result;

}
//нахождение седловой точки
void getSaddlePoints(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    int *maxInColums = searchMaxInEachColumMatrix(matrix);//хранится максамальные элементы каждого столбца
    for(int i=0; i<NUMBER_LINE; i++){//проходим по каждой строке
        int minLine = searchMinInLine(matrix[i], NUMBER_COLUM);//минимальный элемент в строке
        for(int j=0; j<NUMBER_COLUM; j++){//проходим по каждому элементу строки
            if(matrix[i][j] == minLine){//если элемент совпадает с минимальным строке, то идем дальше(т.к в сроке может быть несколько минимальных элементов)
                if(matrix[i][j] == maxInColums[j]){//если элемент равен максимальному элементу в своем столбце, то это седловая точка
                    cout<<"Saddle Point: "<<matrix[i][j]<<" ("<<i+1<<','<<j+1<<");"<<endl;//вывод седловой точкм..значение и индекс элемента
                }
            }
        }
    }

}
