#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin,str);


    for(char &ch:str){
        if(ch>='a' && ch<='z'){
            ch = ch - 32;
        }else if(ch>='A' && ch<='Z'){
            ch = ch + 32;
        }
    }




cout<<"Converted string: "<<str<<endl;




    return 0;

}