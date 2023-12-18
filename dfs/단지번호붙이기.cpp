#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, cnt = 0;
string map[25];
int visited[25][25];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int dfs(int r, int c){
    
    visited[r][c] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

        if(!visited[nr][nc] && map[nr][nc] == '1'){
            dfs(nr, nc);
        }
    }

    return cnt;
}

int main(){
    fastio();
    int num;
    vector<int> ans;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(!visited[r][c] && map[r][c] == '1') {
                cnt = 0;
                num = dfs(r, c);
                ans.push_back(num);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size()<<endl;

    for(const auto & ele : ans)
        cout << ele << endl;
}
