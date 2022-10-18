#include<iostream>
#include<string>
using namespace std;

int main(){
    string line;
    // 每次读入一行
    while(getline(cin, line)){
        // if(!line.empty())
            cout<< line<< endl;
    }
    return 0;
}