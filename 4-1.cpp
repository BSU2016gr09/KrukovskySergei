#include <iostream>

using namespace std;

const int SIZE = 100;

int* createArray (){

    int * a;
    a = new int[SIZE];
    return a;

}

int* multiplyArrays(int* array1, int* array2){

    int* result = createArray();

    for(int i = 0; i<SIZE; i++){
        result[i] = array1[i] * array2[i];
    }

    return result;

}
int* divideArrays(int* array1, int* array2){

    int* result = createArray();

    for(int i = 0; i<SIZE; i++){
        if(array2[i] != 0){
            result[i] = array1[i] / array2[i];
        }else{
            //если происходит деление на 0 то записывается число -131313;
            result[i] = -131313;
        }
    }

    return result;

}

int* additionArrays(int* array1, int* array2){

    int* result = createArray();

    for(int i = 0; i<SIZE; i++){
        result[i] = array1[i] + array2[i];
    }

    return result;

}

int* subtractionArrays(int* array1, int* array2){

    int* result = createArray();

    for(int i = 0; i<SIZE; i++){
        result[i] = array1[i] - array2[i];
    }

    return result;


}

int main()
{
   int* array1 = createArray();
   int* array2 = createArray();
   array1[0] = 5;
   array1[1] = 7;
   array1[2] = 3;
   array2[0] = 1;
   array2[1] = 3;
   array2[2] = 4;

   int* result1 = multiplyArrays(array1, array2);
      cout<<result1[0]<<" "<<result1[1]<<" "<<result1[2]<<endl;
    int* result2 = divideArrays(array1, array2);
   cout<<result2[0]<<" "<<result2[1]<<" "<<result2[2]<<endl;
    int* result3 = additionArrays(array1, array2);
   cout<<result3[0]<<" "<<result3[1]<<" "<<result3[2]<<endl;
   return 0;
}
