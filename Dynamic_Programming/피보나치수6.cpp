#include <iostream>
#include <map>

#define endl "\n"
#define MOD 1000000007LL

using namespace std;

long long n;

map<long long, long long> dp;

long long fibo(long long n){
    if(dp[n]) return dp[n];

    long long result;
    if(n % 2 == 0)
        result = (fibo(n/2) * (fibo(n/2 + 1)  + fibo(n/2 - 1))) % MOD;

    else{
        long long half1 = fibo((n-1)/2);
        long long half2 = fibo((n+1)/2);
        result = (half1 * half1 % MOD + half2 * half2 % MOD) % MOD;
    }

    return dp[n] = result % MOD;
}

int main(){
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    cout << fibo(n) << endl;
}
