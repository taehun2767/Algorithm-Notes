#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define MAX 31

int n;
long long dp[MAX][MAX];

using namespace std;

long long solution(int w, int h)
{
    long long &ret = dp[w][h];
    if(ret != -1)
        return ret;

    ret = 0;
    if(w > 0 && h > 0)
        ret = solution(w-1, h+1) + solution(w, h-1);
    else if(w > 0 && h == 0)
        ret = solution(w-1, h+1);
    else if(w == 0 && h > 0)
        ret = solution(w, h-1);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    
    for(int i = 1; i <=30; i++)
    {
        dp[0][i] = 1;
    }
    while(true)
    {
        cin >> n;
        if(n == 0)
            break;

        cout << solution(n, 0) << endl;;
    }
}

