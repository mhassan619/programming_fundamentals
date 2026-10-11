#include<iostream>
using namespace std;
int x = 10;

void test(int x = 50)
{
    cout << x;
}

int main()
{
    test();
    test(100);
    cout << x;
    return 0;
}
