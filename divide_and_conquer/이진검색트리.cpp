#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int node[10000];

int idx, num;

void traverse(int start, int end){

    if(start >= end)
        return;

    if(start == end-1){
        cout << node[start] << endl;
        return;
    }

    int mid;
    for(mid = start + 1; mid < end; mid++){
        if(node[start] < node[mid])
            break;
    }

    traverse(start + 1, mid);
    traverse(mid, end);

    cout << node[start] << endl;
}

void solve(){
    traverse(0, idx);
}

int main(){
    fastio();
    while(cin >> num){
       node[idx++] = num;
    }
    solve();
}
