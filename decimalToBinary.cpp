#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int ans = 0;
    int i = 0;
    while(n!=0){
        int bit = n&1;
        ans = (bit*(pow(10,i)))+ans;
        n=n>>1;
        i++;
    }
   
    // while(n!=0){
    //     int rem = n%2;
         
    //     ans = (rem * 10) + ans;  
    //     n=n/2;
      

    // }
    cout<<"Required Answer is: "<< ans << endl;

    return 0;
}