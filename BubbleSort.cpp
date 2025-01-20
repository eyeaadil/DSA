#include<bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
            
        }
        if(swapped==false){
            break;
        }
        
    }
    
}

void print(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int a[]={98,78,56,87,65};
    print(a,5);

    cout<<endl;
    bubbleSort(a,5);
    print(a,5);

    return 0;
}