#include<iostream>
using namespace std;
long factorial(long n){
    long fact = 1;
    for(long i=1;i<=n;i++){
        fact = fact * i;

    }
    return fact;
};

long ncr(int n ,int r){
    long num = factorial(n);
    long den = factorial(n-r)*factorial(r);
    long ans = num/den;
    return ans;

}
int main(){
    int n,r;
    cout<<"enter n and r "<< endl;
    cin>> n >>r;
    long ans = ncr(n,r);
    cout<<"required ans is "<<ans;

}