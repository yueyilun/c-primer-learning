#include<iostream>
using namespace std;

// void screen(int x = 10; int y = 20; char z = 'c')
// {
//     cout<<a<<" "<<def<<endl;
// }

int a = 80;
int b = 100;
char def = ' ';

void screen(int = a, int = b, char = def)
{
    cout<<a<<" "<<b<<" "<<def<<endl;
}

void f2()
{
    def = '*';
    // int a = 200;
    a = 200;
    screen();
}

int main()
{
    screen();
    f2();
    return 0;
}