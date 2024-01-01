#include <iostream>
#include <queue>
#include <cstring>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int t, a, b;
bool visited[10000];

void bfs(int a, int b){
    queue<pair<int, string>> que;
    que.emplace(a, "");
    visited[a] = true;

    while(!que.empty()){
        int curNum = que.front().first;
        string curStr = que.front().second;
        que.pop();

        if(curNum == b){
            cout << curStr << endl;
            return;
        }

        int d = curNum * 2 % 10000;
        if(!visited[d]){
            que.emplace(d, curStr + "D");
            visited[d] = true;
        }

        int s = curNum -1 >= 0 ? curNum - 1 : 9999;
        if(!visited[s]){
            que.emplace(s, curStr + "S");
            visited[s] = true;
        }

        int l = curNum % 1000 * 10 + curNum / 1000;
        if(!visited[l]){
            que.emplace(l, curStr + "L");
            visited[l] = true;
        }

        int r = curNum / 10 + curNum % 10 * 1000;
        if(!visited[r]){
            que.emplace(r, curStr + "R");
            visited[r] = true;
        }
    }
}

int main(){
    fastio();
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(visited, false, sizeof(visited));
        bfs(a, b);
    }
}
