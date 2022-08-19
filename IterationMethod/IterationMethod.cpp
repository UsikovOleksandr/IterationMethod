#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

double function(double x)
{
    return pow(x, 3) - 0.2 * pow(x, 2) + 0.2 * x - 1.2;
}

double findRoot(double a, double b, double fault, int calc)
{
    int calc2 = calc;
    while (fabs(function(b)) > fault)
    {
        a = b - ((b - a) * function(b)) / (function(b) - function(a));
        b = a - ((a - b) * function(a)) / (function(a) - function(b));
        calc2 += 1;
    }
    cout << "Quantity of iterations = " << calc2 << endl;
    return b;
}
int main()
{
    int calc = 0;
    double a, b, fault;

    a = 0.5;
    b = 1.5;
    fault = 0.01;

    cout << "Root of the equation x = " << findRoot(a, b, fault, calc) << " Fault: " << fault << endl;
    fault = 0.001;
    cout << "Root of the equation x = " << findRoot(a, b, fault, calc) << " Fault: " << fault << endl;
    fault = 0.00001;
    cout << "Root of the equation x = " << findRoot(a, b, fault, calc) << " Fault: " << fault << endl;
    return 0;
}