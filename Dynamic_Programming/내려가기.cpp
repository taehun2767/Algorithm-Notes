#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n;
int input[3];
int minDp[3] = {0,};
int maxDp[3] = {0,};

int tmp1, tmp2, tmp3;

int main(){

    fastio();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[0] >> input[1] >> input[2];

        tmp1 = minDp[0], tmp2 = minDp[1], tmp3 = minDp[2];

        minDp[0] = min(tmp1, tmp2) + input[0];
        minDp[1] = min(min(tmp1, tmp2), tmp3) + input[1];
        minDp[2] = min(tmp2, tmp3) + input[2];

        tmp1 = maxDp[0], tmp2 = maxDp[1], tmp3 = maxDp[2];

        maxDp[0] = max(tmp1, tmp2) + input[0];
        maxDp[1] = max(max(tmp1, tmp2), tmp3) + input[1];
        maxDp[2] = max(tmp2, tmp3) + input[2];
    }
    cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << " " << min(min(minDp[0], minDp[1]), minDp[2]) << endl;
}
