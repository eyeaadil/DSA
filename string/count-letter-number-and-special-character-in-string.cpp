#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int letter, number, special;
    letter = number = special = 0;
    cout<<"Enter a string:";
    getline(cin,str);


    for(char ch :str){
        if((ch>='a' && ch<='z') || (ch>='A'&&ch<='Z')){
            letter++;
        }else if(ch>='0' && ch<='9'){
            number++;
        }else{
            special++;
        }
    }
    cout<<"Number of letters: "<<letter<<endl;
    cout<<"Number of numbers: "<<number<<endl;
    cout<<"Number of special characters: "<<special<<endl;
    return 0;
}