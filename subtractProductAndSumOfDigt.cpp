#include<iostream>
using namespace std;
int main(){
    int product = 1;
    int sum = 0;
    int n ;
    cout<<"enter the number n "<<endl;
    cin>>n;
    while(n!=0){
        int rem = n%10;
        product = product * rem;
        sum = sum + rem;
        n = n/10;

    }
    int ans = product - sum;
    cout<<"required ans is "<<ans<<endl;;

}