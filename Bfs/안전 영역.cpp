#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'
#define MAX 101

using namespace std;

int n;
int ans = 0;
int region;
int regions[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct pos
{
    int x;
    int y;
};

int bfs(int y, int x)
{
    queue<pos> que;

    pos cur;
    cur.x = x;
    cur.y = y;
    visited[y][x] = 1;
    que.push(cur);

    while(que.empty() == false)
    {
        pos top = que.front();
        for(int i = 0; i < 4; i++)
        {
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];

            if(ny >= n || ny < 0 || nx >= n || nx < 0)
                continue;
                
            if(visited[ny][nx] == false)
            {
                pos next;
                next.x = nx;
                next.y = ny;
                visited[ny][nx] = 1;
                que.push(next);
            }
        }
        que.pop();
    }

    return 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxNum = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >>region;
            regions[i][j] = region;
            maxNum = max(maxNum, region);
        }
    }
    
    
    int maxAns = 0;
    for(int i = 0; i <= maxNum; i++)
    {
        ans = 0;
        memset(visited, 0, sizeof(visited));
        
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(regions[j][k] <= i)
                    visited[j][k] = 1;
            }
        }
        
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(visited[j][k] == false)
                {
                    ans += bfs(j, k);
                }
            }
        }
        maxAns = max(maxAns, ans);
    }
    cout << maxAns << endl;
}
