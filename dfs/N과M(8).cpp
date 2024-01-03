#include <iostream>
#include <algorithm>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 9

using namespace std;


int n, m;
int nums[MAX];
int arr[MAX];

void dfs(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    else{
        for(int i = num; i < n; i++){
            arr[cnt] = nums[i];
            dfs(i, cnt + 1);
        }
    }
}

int main(){
    fastio();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    dfs(0, 0);
}
