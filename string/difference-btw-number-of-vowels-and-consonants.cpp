#include<iostream>
#include<string>

using namespace std;
int main(){
    string str;
    int vowels,consonants;
    vowels = consonants = 0;

    cout<<"Enter a string:";

    getline(cin,str);

    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'|| ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            vowels++;
        }else if((ch>='a' && ch<='z') || (ch>='A'&&ch<='Z')){
            consonants++;
        }
        

    }

    cout<<"Number of vowels: "<<vowels<<endl;
    cout<<"Number of consonants: "<<consonants<<endl;
    cout<<"Difference between number of vowels and consonants: "<<vowels-consonants<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;

}