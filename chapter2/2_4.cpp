#include<iostream>
using namespace std;

int main(){
    double dval = 3.14;
    // 此处编译器生成了一个临时的整型变量
    //const int temp = dval; // create a temporary const int from the double
    //const int &ri = temp; // bind ri to that temporar
    const int &ri = dval;
    cout<<dval<<endl;
    cout<<ri<<endl;

    int i = 42;
    const int &r2 = i;
    cout<<"i="<<i<<endl;
    cout<<"r2="<<r2<<endl;

    i = 12;
    cout<<"-------"<<endl;
    cout<<"i="<<i<<endl;
    cout<<"r2="<<r2<<endl;

}