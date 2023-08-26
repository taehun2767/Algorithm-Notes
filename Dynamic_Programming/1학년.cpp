#include <iostream>

using namespace std;

int n;
int operands[101];
int dp[101][21];

void solution()
{
    int target =operands[n];
    dp[n][target] = 1;

    for(int i = n - 1; i > 0; i++)
    {
        for(int j = 1; j <= 20; j++)
        {
              // 추가 수정 필요
            int cur = operands[i];
            if(dp[i + 1][j] + cur >= 0 && dp[i + 1][j] + cur <= 20)
            {

                dp[i][j] += dp[i+1][j];
            }
          
        }
    }
}

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> operands[i];
    }


}
