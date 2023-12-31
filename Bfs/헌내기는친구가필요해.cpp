#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int n, m ,sr, sc;
string row;
string campus[600];
bool visited[600][600];

struct info{
    int r;
    int c;
    info(int R, int C) : r(R), c(C){};
};

void findFriends(int sr, int sc){
    int count = 0;
    queue<info> que;
    visited[sr][sc] = true;
    que.emplace(sr, sc);
    while(!que.empty()){
        info cur = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if(campus[nr][nc] != 'X' && !visited[nr][nc]){
                visited[nr][nc] = true;
                que.emplace(nr, nc);
                if(campus[nr][nc] == 'P')
                    count++;
            }
        }
    }

    if(count != 0)
        cout << count << endl;
    else
        cout << "TT" << endl;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> row;
        campus[i] = row;
        for(int j = 0; j < m; j++){
            if(row[j] == 'I'){
                sr = i;
                sc = j;
            }
        }
    }

    findFriends(sr, sc);

}
