#include<iostream>
#include <algorithm>  // for reverse() and equal()
using namespace std;

bool isplaindrome(string &str){
    string reverseString = str;
    reverse(reverseString.begin(),reverseString.end());

    return reverseString==str;
}
int main(){

    string str;
    cout<<"Enter string"<<endl;
    getline(cin,str);


    if(isplaindrome(str)){
        cout<<"String is palindrome"<<endl;
    }
    else{
        cout<<"String is not palindrome";
    }


}