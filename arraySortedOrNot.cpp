#include<iostream>
using namespace std;


int sortedArray(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return 0;
            
        }
    }
    return 1;
}
int main(){

int arr[5] = {1,6,4,4,5};


int ans = sortedArray(arr,5);
cout<<"Required ans is:"<<ans<<endl;


    return 0;
}