#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define MAX 101

using namespace std;

int n,k;
int coin;
vector<int> coins;
int dp[10001];

void solution()
{
    for(int i =coins[1]; i <= k; i++)
    {
        for(auto c : coins)
        {
            if(i-c >= 0 && dp[i-c] != -1)
                dp[i] = min(dp[i], 1 + dp[i-c]);
        }
        dp[i] = dp[i] != 10001 ? dp[i] : -1;
    }
    cout << dp[k];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n >> k;


    dp[0] =0;
    for(int i= 1; i <=10001; i++)
    {
        dp[i] = 10001;
    }
    for(int i = 1;i <= n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }
    sort(coins.begin(), coins.end());

    solution();
    
}
