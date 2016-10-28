#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
void initializeArray(int * array, int  N)
{
    for(int i=0; i<N; i++){
        array[i]=rand()% N+1;
    }
}
void printArray(int * array, int N)
{
    for(int i=0; i<N; i++)
    {
        cout<<"|" <<array[i]<< "|  " ;
    }
}
void initializeArrayWithParam(int *array, int N, int param){
    for(int i=0; i<N; i++){
        array[i]=param;
    }
}
int * mixArray(int * array, int N ){
    int * B = new int [N];
    int param;

    initializeArrayWithParam(B, N, param);
    int countChangeElements = 0;
    while(countChangeElements < N){
        int k=rand()%N;
        if(B[k] == param){
            B[k] = array[countChangeElements];
            countChangeElements++;
        }
    }

    return B;
}

int main(){
setlocale(LC_ALL, "rus");
int const N=20;
int *  A = new int [N];
  cout<< "Первый массив: \n";
initializeArray(A, N);
printArray(A, N);
int *B;
cout<< "\n Перемешенный массив: \n";
B = mixArray(A,N);
printArray(B,N);
return 0;
}
