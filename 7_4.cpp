#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
    В матрице (m,n) найти те строки и вывести их номера, элементы которых образуют возврастающую последовательность
*/
const int NUMBER_LINE = 3;//количество строк в матрице
const int NUMBER_COLUM = 3;//количество столбцов в матрице

//печатает матрицу
void printMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//заполняет матрицу
void initializeMatrix(int matrix[NUMBER_LINE][NUMBER_COLUM]);
//вывод номеров строк матрицы элементы которой образуют возрастающую последовательность
void getIndexSequenceLines(int matrix[NUMBER_LINE][NUMBER_COLUM]);

int main()
{
    int matrix[NUMBER_LINE][NUMBER_COLUM];
    initializeMatrix(matrix);
    printMatrix(matrix);
    getIndexSequenceLines(matrix);
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
//вывод номеров строк матрицы элементы которой образуют возрастающую последовательность
void getIndexSequenceLines(int matrix[NUMBER_LINE][NUMBER_COLUM]){
    cout<<"Result: ";
    if(NUMBER_COLUM == 1){
        for(int i = 0; i < NUMBER_LINE; i++){
            cout<<i+1<<"  ";
        }
        return;
    }
    //возрастающая последовательность может образоваться если идти не только с начала строки но и из конца строки
    for(int i = 0; i < NUMBER_LINE; i++){
        int criterion = 0; //если =1 то возврастающаю последовательность.. -1 убывающая.. 0 пока не определена(если она убывающая сначала, то она возрастающая сконца)
        for(int j = 0; j < NUMBER_COLUM; j++){
            if((matrix[i][j+1] > matrix[i][j]) && criterion == 0){
                criterion = 1;
            }else if((matrix[i][j+1] < matrix[i][j]) && criterion == 0){
                criterion = -1;
            }
            if(criterion == 0){
                continue;
            }
            if(j == NUMBER_COLUM-1){
                cout<<i+1<<"  ";
                continue;
            }
            if((matrix[i][j+1] < matrix[i][j]) && criterion == 1){
                break;
            }else if((matrix[i][j+1] > matrix[i][j]) && criterion == -1){
                break;
            }

        }
    }

}


