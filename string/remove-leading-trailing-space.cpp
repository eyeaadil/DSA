#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    int start = 0;
    int end = str.length()-1;
    while(start<str.length() && str[start]==' '){
        start++;
    }
    while(end>=0 && str[end]==' '){
        end--;
    }
    string newStr = str.substr(start,end-start+1);
    cout<<"New string: "<<newStr<<endl;

    return 0;
}