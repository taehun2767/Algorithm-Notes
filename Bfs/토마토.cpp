#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m;
vector<pair<int, int>> sources;
int box[1001][1001] = {0, };
bool visited[1001][1001];

int dr[4] = {0, 1, 0 , -1};
int dc[4] = {1, 0, -1, 0};

struct info{
    int r;
    int c;
    int count;
    info() {};
    info(int R, int C, int COUNT) : r(R), c(C), count(COUNT) {};
};

void bfs(){
    queue<info> que;
    for(const auto& s : sources){
        que.emplace(s.first, s.second, 0);
        visited[s.first][s.second] = true;
    }

    info cur;
    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            int ncount = cur.count + 1;

            if(nr <= 0 || nr > n || nc <= 0 || nc > m)
                continue;

            if(!visited[nr][nc] && box[nr][nc] != -1){
                que.emplace(nr, nc, ncount);
                visited[nr][nc] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && box[i][j] != -1){
                cout << -1 << endl;
                return ;
            }
        }
    }

    cout << cur.count << endl;
};


int main(){
    fastio();
    int num, r, c;

    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> num;
            box[i][j] = num;
            if(num == 1)
                sources.emplace_back(i, j);
        }
    }

    bfs();
}
