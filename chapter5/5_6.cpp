#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    int a=2,b=3;
    try{
        if(a != b){
            throw runtime_error("Data is not same");
        }
    }catch(runtime_error err)
    {
        // what()这个成员函数返回前面runtime_error定义的初始值，即“Data is not same”
        cout<<err.what()<<endl;
    }
    return 0;
}