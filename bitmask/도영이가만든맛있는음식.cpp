#include <iostream>
#include <vector>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, s, b;

vector<pair<int, int>> tastes;

int answer = 1e9;


int main(){

    fastio();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s >> b;
        tastes.emplace_back(s, b);
    }

    for(int i = 1; i < (1 << n); i++){
        int sMult = 1, bSum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sMult *= tastes[j].first;
                bSum += tastes[j].second;
            }
        }
        answer = min(answer, abs(sMult - bSum));
    }

    cout << answer << endl;
}
