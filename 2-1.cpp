#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//инициализирует массив
void initializeArray(int *array, int N){
    for(int i = 0; i<N; i++){
        array[i] =  rand()%N + 1;
    }
}
//печатует массив
void printArray(int *array, int N){
    for(int i = 0; i<N; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}
//меняет местами элементы в массиве
int* reverseArray(int *array, int N){
    int * B = new int[N];
    for(int i = N-1; i>=0; i--){
        B[N-1-i] = array[i];
    }
    return B;
}

int main()
{
  int const N = 10;
  int * A = new int[N];
  initializeArray(A, N);
  printArray(A, N);
  int * B;
  B = reverseArray(A, N);
  printArray(B, N);
  return 0;
}
