
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
//проверяет строку на нули..если все нули то тру если нет но фолз
bool checkLineOnNull(int arr[], int length);
//печатает матрицу(для того что бы пичалось конкретное число строк и столбцов матрицы)
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM], int numLine, int numColum);
//удаление строк где все элементы 0
void deleteNullLinesFromMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    cout<<endl<<endl<<endl<<endl<<endl;
    deleteNullLinesFromMatrix(matrix);

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
            if(i==1 || i==0){
                matrix[i][j] = 0;
                continue;
            }
            matrix[i][j] = rand()%10;
        }

    }
}
//проверяет строку на нули..если все нули то тру если нет но фолз
bool checkLineOnNull(int arr[], int length){

    bool result = true;
    for(int i = 0; i < length; i++){
        if(arr[i] != 0){
            result = false;
            break;
        }
    }
    return result;
}

//удаление строк где все элементы 0
void deleteNullLinesFromMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    int numLine = 0;//контролирует кольчество пройденых строк
    int numColum = NUMBER_COLUM;
    int i = 0;//номер текущей строки
    int countLine = NUMBER_LINE;//количество строк которые осталось проверить
    while(countLine){
            if(checkLineOnNull(matrix[i], NUMBER_COLUM)){//проверка строки на нули
                for(int q=i; q<NUMBER_LINE-1; q++){//подтягивание строк ввер
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

