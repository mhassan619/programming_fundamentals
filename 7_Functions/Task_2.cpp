#include<iostream>
using namespace std;
int test(int x)
{
    cout << x;
    return x + 5;
}

int main()
{
    int a = test(10);
    cout << a;
    return 0;
}
