#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int board[51][51] = {0, };
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;

int main(){
    cin >> n >> m;

    //input
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                houses.emplace_back(i, j);
            else if(board[i][j] == 2)
                chickens.emplace_back(i, j);
        }
    }
    int r = houses.size();
    int c = chickens.size();

    //
    vector<vector<int>> distance(r, vector<int>(c, 0));
    for(int i = 0; i < r ; i++){
        for(int j = 0; j < c; j++){
            distance[i][j] = abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second);
        }
    }


    vector<bool> isPossible(c, true);


    int minSum = 1000000;

    for(int i = 0; i < c-m; i++){
        isPossible[i] = false;
    }
    do{
        int tempSum = 0;
        for(int i = 0; i < r; i++){
            int minValue = 1000000;
            for(int j = 0; j < c; j++){
                if(isPossible[j])
                    minValue = min(minValue, distance[i][j]);
            }
            tempSum += minValue;
        }
        minSum = min(minSum, tempSum);
    } while(next_permutation(isPossible.begin(), isPossible.end()));


    cout << minSum << endl;
}
