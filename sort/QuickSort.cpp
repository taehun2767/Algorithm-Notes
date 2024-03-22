#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void QuickSort(T& a, const int left, const int right){
    if(left >= right) return;

    int pivot = a[left];
    int i = left;
    int j = right + 1;
    do
    {
        do i++; while(a[i] < pivot);
        do j--; while(a[j] > pivot);
        if(i < j) swap(a[i], a[j]);
    } while(i < j);
    swap(a[left], a[j]);

    QuickSort(a, left, j);
    QuickSort(a, i, right);
}

int main(){
    vector<int> vec = {5 ,1 ,3, 2, 4};
    QuickSort(vec , 0, 5);
    for(auto x : vec){
        cout << x << " ";
    }

    cout << endl;
}
