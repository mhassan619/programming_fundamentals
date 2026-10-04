#include<iostream>
using namespace std;
void fun(int &a, int b)
{
    a = a + 10;
    b = b + 20;
}

int main()
{
    int x = 5;
    int y = 7;

    fun(x, y);

    cout << x << " " << y;
    return 0;
}
