#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

void countOccurrences(string &str){
    unordered_map<char,int>mp;

    int maxFreq = 0;
     char maxChar = '\0', minChar = '\0';
    int minFreq = INT_MAX;
    


    for(char c:str){
        mp[c]++;
    }

    // traverse the map
    for(auto it:mp){
        int freq = it.second;
        char ch = it.first;

        if(freq>maxFreq){
            maxFreq = freq;
            maxChar = ch;
        }

        if(freq<minFreq){
            minFreq = freq;
            minChar = ch;
        }
    }
    cout<<"Maximum frequency character: "<<maxChar<<endl;
    cout<<"Minimum frequency character: "<<minChar<<endl;

}
int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin,str);

    countOccurrences(str);

    return 0;

}