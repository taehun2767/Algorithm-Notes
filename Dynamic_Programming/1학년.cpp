#include <iostream>

using namespace std;

int n;
int operands[101];
long long  dp[101][21];

void solution()
{

    dp[1][operands[1]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0 ; j <= 20; j++)
        {
            if(dp[i][j] == 0)
                continue;

            int p = j + operands[i + 1];
            if(p >= 0 && p <= 20)
                dp[i + 1][p] += dp[i][j];

            int m = j - operands[i + 1];
            if(m >= 0 && m <= 20)
                dp[i + 1][m] += dp[i][j];
        }
    }

    cout << dp[n-1][operands[n]] << endl;
}

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> operands[i];
    }
    solution();


}
