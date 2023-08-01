#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101
using namespace std;

int relationship[MAX][MAX];
int visited[MAX];

int n;
int x, y;;
int m;
int p, c;


int bfs(int x, int y)
{
    queue<int> que;
    que.push(x);
    visited[x] = 0;
    while(que.empty() == false)
    {
        int cur = que.front();
        for(int i = 1; i <= n; i++)
        {
            if(relationship[cur][i] == 1 && visited[i] == -1)
            {
                if(i == y)
                    return visited[cur] + 1;
                
                visited[i] = visited[cur] + 1;
                que.push(i);
            }
        }
        que.pop();
    }
    return -1;
}


int main()
{
    fastio();
    memset(relationship, 0, sizeof(relationship));
    memset(visited, -1, sizeof(visited));
    cin >> n;
    cin>> x >> y;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>> p >> c;
        relationship[p][c] = 1;
        relationship[c][p] = 1;
    }

    cout<<bfs(x, y);
    
}


