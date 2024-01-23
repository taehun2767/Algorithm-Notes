#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, k;

int bitCount(int x){
    if(x == 0) return 0;
    return x % 2 + bitCount(x/2);
}

void solve(){
    for(int i =0;;i++){
        if(bitCount(n) <= k){
            cout << i;
            return ;
        }
        n++;
    }
}

int main(){
    fastio();
    cin >> n >> k;
    solve();
}
