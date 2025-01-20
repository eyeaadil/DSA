#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n  "<<endl;
    cin>>n;
    int a=0;
    int b = 1;
    for(int i = 2;i<n;i++){
        int sum = a+b;
        cout<<sum  <<endl;
        a=b;
        b=sum;
    }
    cout<< "nth term of fibbonacci series is: "<<b;
}