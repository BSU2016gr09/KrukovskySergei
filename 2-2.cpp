#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
//инициализирует массив
void initializeArray(int *array, int N){
    for(int i = 0; i<N; i++){
        array[i] =  rand()%(2*N+1)-N;
    }
}
//печатует массив
void printArray(int *array, int N){
    for(int i = 0; i<N; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}

//сдвиг в право
void rightShift(int *array, int N){
    int k = array[N-1];
    for(int i = N-1; i>0; i--){
        array[i] = array[i-1];
    }
    array[0] = k;
}
//сдвиг в лево
void leftShift(int *array, int N){
    int k = array[0];
    for(int i = 0; i<N-1; i++){
        array[i] = array[i+1];
    }
    array[N-1] = k;
}
int main()
{
  int const N = 20;
  int * A = new int[N];
  initializeArray(A, N);
  printArray(A, N);
   rightShift(A, N);
  printArray(A, N);
  leftShift(A, N);
  printArray(A, N);
  return 0;
}
