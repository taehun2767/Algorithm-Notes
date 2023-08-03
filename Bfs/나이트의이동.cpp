#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'
#define MAX 301

using namespace std;

int t;
int n;
int sx, sy;
int ex, ey;
int visited[MAX][MAX];

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct info
{
    int x;
    int y;
    int count;
};

int bfs(int sx, int sy)
{
    if(sx == ex && sy == ey)
        return 0;
    
    info cur;
    cur.x = sx;
    cur.y = sy;
    cur.count = 0;
    visited[sy][sx] = 1;
    queue<info> que;
    que.push(cur);

    while(que.empty() == false)
    {
        cur = que.front();
        for(int i =0; i <8; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx == ex && ny == ey)
                return cur.count + 1;
            
            if(nx >= n || nx <0 || ny >= n || ny <0)
                continue;

            if(visited[ny][nx])
                continue;
            
            visited[ny][nx] = 1;
            info next;
            next.x = nx;
            next.y = ny;
            next.count = cur.count + 1;
            que.push(next);
        }
        que.pop();
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        cin >> sx >> sy;
        cin >> ex >> ey;
        cout << bfs(sx, sy)<< endl;
    }
    return 0;
    
}
