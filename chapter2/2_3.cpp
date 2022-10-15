#include<iostream>
using namespace std;

// int main(){
//     int i = 42;
//     int &r = i; // & follows a type and is part of a declaration; r is areference
//     int *p; // * follows a type and is part of a declaration; p is a pointer
//     p = &i; // & is used in an expression as the address-of operator
//     *p = i; // * is used in an expression as the dereference operator
//     int &r2 = *p; // & is part of the declaration; * is the dereference operator
//     cout<<r2<<endl;
//     cout<<i<<endl;
// }


// 该程序无法成功编译，不能直接操作void*指针所指的对象
int main(){
    double obj = 3.14;
    void *p = &obj;
    // error: ‘void*’ is not a pointer-to-object type
    cout<<*p<<endl;
    return 0;
}

