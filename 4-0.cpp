#include <iostream>
#include <math.h>
#include <iomanip>
// Постройте график функции sin(2x)/x
using namespace std;
void drawGraph();
int main()
{
    drawGraph();
    return 0;
}
// функциия построения графика.
void  drawGraph()
{
    for (float x=-6, y; x<=6 ; x+=0.1)
    {//А эти числа как вычислены? Подбором???? Не прикольно....
        y=(sin(2*x)/x)*30; // 30 - число отвечающее за маштаб графика.
        cout<< setw(y+20) << "*\n"; // 20 - отступ от края консоли.
    }
}

