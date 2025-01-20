#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"enter the value of n"<<endl;
    bool isPrime = 1;
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime == 0){
        cout<< "not a prime numeber"<<endl;
    }else{
        cout<< "primr number";
    }
}