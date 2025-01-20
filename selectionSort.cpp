#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr, int n){
    int min_idx;
    for (int i =0; i<n; i++)
    {
        int min_idx = i;

        for (int j=i+1; j < n; j++)
        {
            if (arr[j]<arr[min_idx])
            {
                //swap(arr[j],arr[min_idx]);
                min_idx = j;
            }
            
        }
        swap(arr[i],arr[min_idx]);
        
    }
    
}


void print(vector<int>arr,int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
//   random input ke liye

    vector<int>arr;
    for(int i=0;i<10;i++){
        int ele = rand();
        arr.push_back(ele);
    }

   
   int n = arr.size();

    print(arr,n);
    selectionSort(arr,n);
    cout<<endl;
    print(arr,n);



    return 0;
}