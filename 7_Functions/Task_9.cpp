#include<iostream>
using namespace std;
void test(int x, int &y)
{
    x = 100;
    y = 200;
}

int main()
{
    int a = 10;
    int b = 20;

    test(a, b);

    cout << a << " " << b;
    return 0;
}
