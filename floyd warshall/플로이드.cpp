#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 101
#define INF 1e9
using namespace std;

int n, m, a, b, c;

int result[MAX][MAX];

void initialize(){
    fastio();
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) result[i][j] = 0;
            else result[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        result[a][b] = min(result[a][b], c);
    }
}

void floydWarshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(result[i][j] > result[i][k] + result[k][j])
                    result[i][j] = result[i][k] + result[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(result[i][j] < INF)
                cout << result[i][j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main(){
    initialize();
    floydWarshall();
}
