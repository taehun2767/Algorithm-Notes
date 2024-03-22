#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sorted[100001];


//merge sort
void merge(vector<int>& arr, int left, int mid, int right){

    int i = left;
    int j = mid + 1;
    int idx = left;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            sorted[idx++] = arr[i++];
        else
            sorted[idx++] = arr[j++];
    }

    if(i > mid){
        for(int m = j; m <= right; m++){
            sorted[idx++] = arr[m];
        }
    }
    else {
        for(int m = i; m <= mid; m++){
            sorted[idx++] = arr[m];
        }
    }

    for(int n = left; n <= right; n++){
        arr[n] = sorted[n];
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int>& arr){
    mergeSort(arr, 0, arr.size()-1);
}

int main(){
    //mergesort
    vec = {3 ,5 ,1, 2, 4, -1, -3};
    mergeSort(vec);
    for(auto x : vec){
        cout << x << " ";
    }
    cout << endl;
}
