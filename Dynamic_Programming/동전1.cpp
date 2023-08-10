#include <iostream>
#include <cstring>
#include <queue>

#define endl '\n'
#define MAX 101

using namespace std;

int n,k;
int coins[MAX];
int dp[10001];


void solution(int idx)
{
    dp[0] = 1;
    for(int i =1; i <= n; i++)
    {
        for(int j = coins[i]; j <=k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    cout<<dp[k];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>n >>k;
    for(int i = 1;i <= n; i++)
    {
        cin >> coins[i];
    }

    solution(k);
    
}
