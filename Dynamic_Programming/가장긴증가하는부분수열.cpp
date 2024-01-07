#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false);
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int mem[MAX] = {0,};

void lcs(){
    int sz = 0;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(mem, mem + sz, arr[i]);
        *it = arr[i];
        if(it - mem == sz)
            sz++;
    }
    cout << sz << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    lcs();
}
