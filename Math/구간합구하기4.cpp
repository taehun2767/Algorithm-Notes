#include <iostream>

using namespace std;

int partialSum[100001]= {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num, s, e;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num;
        partialSum[i] = partialSum[i-1] + num;
    }

    for(int j = 0; j < m; j++){
        cin >> s >> e;
        cout << partialSum[e] - partialSum[s-1] << '\n';
    }
}
