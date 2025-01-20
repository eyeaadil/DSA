#include<iostream>
#include<math.h>
using namespace std;
 int max(int *arr,int n){
    int maxi = INT_MIN;

    // without using inbuilt function
          
        // for(int i=0;i<n;i++){
        //     if(maxi<arr[i]){
        //         maxi = arr[i];
        //     }
        // }

// with using inbuilt function 

    for(int i = 0;i<n;i++){
        maxi = max(maxi,arr[i]);
        // without using inbuilt function
          
        // for(int i=0;i<n;i++){
        //     if(maxi<arr[i]){
        //         maxi = arr[i];
        //     }
        // }
    }
    return maxi;
 }
 int min(int *arr,int n){
    int mini = INT_MAX;
    for (int i=0;i<n;i++){
        mini = min(mini,arr[i]);
    }
    return mini;

 }
int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the element of an array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    };
    int maximum_value = max(arr,n);

    cout<<"maximum value is :"<<maximum_value<<endl;

    int minimum_valueIS = min(arr,n);
    cout<<"minimum value is : "<<minimum_valueIS<<endl;
}
