#include <iostream>
#include <math.h>
#include <iomanip>
// ��������� ������ ������� sin(2x)/x
using namespace std;
void drawGraph();
int main()
{
    drawGraph();
    return 0;
}
// �������� ���������� �������.
void  drawGraph()
{
    for (float x=-6, y; x<=6 ; x+=0.1)
    {
        y=(sin(2*x)/x)*30; // 30 - ����� ���������� �� ������ �������.
        cout<< setw(y+20) << "*\n"; // 20 - ������ �� ���� �������.
    }
}

