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

    cout <<"\n ����� ����� ����� n �����: " << digit;
    return 0;
}
int main()
{ setlocale(LC_ALL, "rus");
    int n;
    cout << "������������ ������ � ���������� ����������� �����, ��������� ������������ �����, ��������� � ������� �� ����� ����� ���� ��������� ������������� �����." << endl;
    cout << "������� ����������� �����: ";
    cin >> n ;
    if (n>0){

        digitSum(n);
    }
    else cout << "���� �� ��������!";
    return 0;
}
