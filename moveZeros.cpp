#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZero(vector <int> arr){
    int n = arr.size();
    int i = 0;
    int k = 0;

    while(i<n){
        if(arr[i]!=0){
            arr[k] = arr[i];
            k++;
            i++;
        }
    }
    return arr;

}

void print(vector<int>arr){
    int n =arr.size();
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    // use two pointer approach
    vector<int>v;
     v.push_back(2);
     v.push_back(0);
     v.push_back(1);
     v.push_back(3);
     v.push_back(4);
     v.push_back(0);
     v.push_back(0);

     print(v);
 vector<int>ans = moveZero(v);
 print(ans);


 return 0;

}