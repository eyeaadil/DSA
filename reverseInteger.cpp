#include<iostream>
#include<math.h>
using namespace std;
int reverse(int n){
    int ans=0;
   while(n!=0){
    int digit = n%10;
    ans = (ans*10)+digit;
    n =n/10;
    if(ans<(INT_MIN/10)){
        return 0;
    }
    if(ans>(INT_MAX/10)){
        return 0;
    }
    
   }
   return ans;
}

int main(){
int n;
cout<<"Enter the value of n: ";
cin>>n;
int ans = reverse(n);
cout<<"Reverse answer  is:"<<ans<<endl;

    return 0;
}