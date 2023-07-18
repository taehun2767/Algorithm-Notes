#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

#define endl '\n'
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 16

using namespace std;


int n;
int ans = 0;
int queens[MAX];


bool check(int r, int c, int queens[])
{
    for(int i = 0; i < r; i++)
    {
        if(queens[i] == c || abs(c - queens[i]) == abs(r - i))
            return false;
    }
    return true;
}

void backtracking(int r, int queens[])
{
    if (r == n)
    {
        ans += 1;
        return ;
    }

    if (r > n)
        return ;
    
    for (int c =0; c <n; c++)
    {
        if (check(r, c, queens) == false)
            continue;

        queens[r] = c;
        backtracking(r+1, queens);
        queens[r] = -1;
    }
    
}

int main(int argc, char* argv[])
{
    
    fastio();
    cin >> n;
    memset(queens, -1, sizeof(queens));
    backtracking(0,  queens);
    cout<<ans;
    return 0;
}
