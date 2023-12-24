#include <iostream>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int jump[101] = {0,};
int map[101] = {0,};
bool visited[101];
int n, m, x, y;

void solution(){

    queue<pair<int, int>> que;
    que.emplace(1, 0);
    visited[1] = true;

    while(!que.empty()){
        pair cur = que.front();
        que.pop();

        if(cur.first == 100){
            cout << cur.second << endl;
            return;
        }

        for(int i = 1; i <= 6; i++){
            int npos= cur.first + i;
            int ncount = cur.second + 1;

            if(npos > 100)
                continue;

            if(jump[npos] != 0){
               npos = jump[npos];
            }

            if(!visited[npos]){
                que.emplace(npos, ncount);
                visited[npos] = true;
            }
        }
    }
}

int main(){
    fastio();

    cin >> n >> m;

    while(n--){
       cin >> x >> y;
       jump[x] = y;
    }
    while(m--){
        cin >> x >> y;
        jump[x] = y;
    }

    solution();
}
