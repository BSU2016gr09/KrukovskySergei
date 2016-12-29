#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
    Транспонировать случайную квадратную матрицу
*/
const int NUMBER_LINE = 3;//количество строк в матрице
const int NUMBER_COLUM = 3;//количество столбцов в матрице

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//транспонирование матрицы
void transportMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    transportMatrix(matrix);
    cout<<endl<<endl<<endl<<endl<<endl;
    printMatrix(matrix);
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
//транспонирование матрицы
void transportMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]){

    if(NUMBER_LINE != NUMBER_COLUM){//если матрица не квадратная
        cout<<"Not equal LINES and COLUMS"<<endl;
        return;
    }

    for(int i=0; i<NUMBER_LINE; i++){
        for(int j=0; j<i; j++){
            int buffer = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = buffer;
        }
    }

}

