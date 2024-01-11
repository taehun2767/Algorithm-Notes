#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false);

using namespace std;

string input1, input2;

int dp[1001][1001] = {0, };

void lcs(string s1, string s2){
    int sz1 = s1.size();
    int sz2 = s2.size();
    for(int i = 0; i < sz1; i++){
        for(int j = 0; j < sz2; j++){
            if(s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j] + 1;

            int otherCase = max(dp[i+1][j], dp[i][j+1]);
            dp[i+1][j+1] = max(dp[i+1][j+1], otherCase);
        }
    }

    cout << dp[sz1][sz2] << endl;
}

int main(){
    fastio();
    cin >> input1;
    cin >> input2;

    lcs(input1, input2);
}
