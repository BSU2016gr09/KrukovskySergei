#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

void initializeArray(int *array, int N){
    for(int i = 0; i<N; i++){
        array[i] =  rand()% N +1;
    }}
int getMaxLengh(int *arr, int N){
    int result = 1;
    int bufferResult = 1;
    for(int i = 0; i < N - 1; i++){
        if(arr[i] == arr[i+1]){
           bufferResult++;
        }else{
            bufferResult = 1;
        }
        if(bufferResult > result){
            result = bufferResult;
        }

    }

    return result;

}
void printArray(int * array, int N)
{ cout<< "Первый массив: \n";
    for(int i=0; i<N; i++)
    {
        cout<<"|" <<array[i]<< "|  " ;
    }
}

int main()
{
setlocale(0, "");

   const int N = 11;
  int * A = new int[N];
   initializeArray(A, N);
   printArray(A, N);
   cout<< "\n Длина последовательности с равными элементами: \n";
   int result = getMaxLengh(A, N);
  cout<<endl;
  cout<< result;
  cout<<endl;
   return 0;
}

