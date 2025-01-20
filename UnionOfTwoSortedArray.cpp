#include <bits/stdc++.h>
using namespace std;
vector<int>findUnion(int arr1[],int arr2[],int n, int m){
    vector<int>result;
    int i= 0;
    int j = 0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j] && result.back()!=arr1[i]){
            result.push_back((arr1[i]));
            i++;
        }
        else{
           if(result.back()!=arr2[j]){
            result.push_back(arr2[j]);
            j++;
           }
        }
    }

    while (i<n)
    {
        if(result.back()!=arr1[i]){
            result.push_back(arr1[i]);
            i++;
        }
    }

    while(j<m){
       if(result.back()!=arr2[j]){
        result.push_back(arr2[j]);
        j++;
       }
    }
    

    return result;
}
int main(){
    int arr1[] = {1,1,2,3,4,5,6};
    int arr2[] = {2,3,4,5,6,7};
  vector < int > Union = findUnion(arr1, arr2, 7, 6);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}