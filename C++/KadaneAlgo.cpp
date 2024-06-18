#include<bits/stdc++.h>
using namespace std;

int kadaneAlgo(vector<int> &arr){
    int size = arr.size();
    int tempSum = 0;
    int max = 0;
    for(int i=0;i<size;i++){
        tempSum+=arr[i];
        if(tempSum>max) max=tempSum;
        if(tempSum<0) tempSum=0;
    }
    return max;
}
int main(){

    vector<int> arr = {1,2,3,4,5,-6,-1,-5,-9,-6};

    int result = kadaneAlgo(arr);

    cout<<result;
}