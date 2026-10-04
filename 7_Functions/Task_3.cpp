#include<iostream>
using namespace std;
int fun(int x)
{
    cout << "A";
    return x * 2;
    cout << "B";
}

int main()
{
    int result = fun(5);
    cout << result;
    return 0;
}
