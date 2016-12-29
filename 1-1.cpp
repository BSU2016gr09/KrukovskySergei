#include <iostream>

using namespace std;
int digitSum(int n )
{
    int digit=0;
    while (n>0)
    {
        digit+=n%10;
        n/=10;
    }

    cout <<"\n Сумма цифор числа n равна: " << digit;
    return 0;
}
int main()
{ setlocale(LC_ALL, "rus");
    int n;
    cout << "Пользователь вводит с клавиатуры натуральное число, проверить корректность ввода, вычислить и вывести на экран сумму цифр введённого пользователем числа." << endl;
    cout << "Введите натуральное число: ";
    cin >> n ;
    if (n>0){

        digitSum(n);
    }
    else cout << "Ввод не коректен!";
    return 0;
}
