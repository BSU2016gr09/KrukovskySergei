#include <iostream>
#include <cstdlib>
using namespace std;
int const N=10;
void initializationArray(int array[], int n)
{
    int i=0;
    while (i<N)
    {
        array[i]= rand() % (3*n+1) - 2*n ;
        i++;
    }
}

void printArray(int array[])
    {
        int i=0;
        while (i<N)
        {
            cout<< array[i] << "   " ;
            i++;
        }

    }

void counterNumbers(int array[])
{
    int i=0, k=0;
    while(i<N)
    {
        if (array[i]>0 && array[i]%2==0)
        {
            k++;
        }
        i++;
    }
    cout<< '\n' << " количество положительных чётных чисел в массиве: "<< k;
}

int main()
{   setlocale(LC_ALL, "rus");
    int array[N], n=0;
    cout<< " Пользователь вводит с клавиатуры натуральное число не большее 100, которое сохраняется в переменную n, проверить корректность ввода, создать массив из 10 случайных целых чисел из отрезка [-2n;n], вывести массив на экран в строку, подсчитать и и вывести на экран количество положительных чётных чисел в массиве. \n";
    cin >> n;
    if (n>0 && n<=100){
    initializationArray(array,n);
    printArray(array);
    counterNumbers(array);
    }
    else cout << "Введённое число не верно!  ";
    return 0;
}
