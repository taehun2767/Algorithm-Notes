#include <iostream>
#include <vector>

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1001

using namespace std;

int n;
int arr[MAX];

int asc[MAX] = {0,};
int desc[MAX] = {0,};

void lis(){
    for(int i = 1; i <= n; i++){
        asc[i] = 1;
        for(int j = i-1; j >= 1; j--){
            if(arr[i] > arr[j])
                asc[i] = max(asc[i], asc[j] + 1);
        }
    }
}

void lds(){
    for(int i = n; i >= 1; i--){
        desc[i] = 1;
        for(int j = i + 1; j <= n; j++){
            if(arr[i] > arr[j])
                desc[i] = max(desc[i], desc[j] + 1);
        }
    }
}

void solve(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, asc[i] + desc[i] - 1);
    }

    cout << ans <<endl;
}


int main(){
    fastio();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    lis();
    lds();
    solve();
}
