#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){

    int i = low;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int l=low;l<=high;l++){
        arr[l] = temp[l-low];
    }
}

void ms(vector<int> &arr, int low, int high){

    if(low==high) return;
    int mid = (low+high)/2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr = {6,5,7,3,4,3,2,1,10};
    ms(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}