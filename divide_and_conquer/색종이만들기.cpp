#include <iostream>
#include <vector>

using namespace std;

int blue = 0;
int white = 0;
int board[128][128] = {0,};

void calBlockNumber(int r, int c, int size){

    int color = board[r][c];

    for(int i = r; i < r + size; i++)
    {
        for(int j = c; j < c + size; j++)
        {
            if(board[i][j] != color){
                size /= 2;
                calBlockNumber(r, c, size);
                calBlockNumber(r, c + size, size);
                calBlockNumber(r + size, c, size);
                calBlockNumber(r + size, c + size, size);
                return;
            }
        }
    }

    blue += color == 1;
    white += color == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    calBlockNumber(0, 0, n);
    cout << white << endl;
    cout << blue << endl;
}
