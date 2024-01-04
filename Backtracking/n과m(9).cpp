#include <iostream>
#include <algorithm>
#include <vector>


#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 9
using namespace std;

int n, m, ele;
vector<int> vec, res;
bool visited[MAX];


void backtracking(int cnt){
    if(cnt == m) {
        for(int i = 0; i < m; i++)
            cout << res[i] << " ";
        cout << endl;
        return;
    }

    int prevNum= -1;
    for(int i = 0; i < n; i++){
        if(visited[i] || prevNum == vec[i])
            continue;

        res.push_back(vec[i]);
        visited[i] = true;
        prevNum = vec[i];
        backtracking(cnt + 1);
        res.pop_back();
        visited[i] = false;
    }
}

int main(){
    fastio();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ele;
        vec.push_back(ele);
    }

    sort(vec.begin(), vec.end());
    backtracking(0);
}
