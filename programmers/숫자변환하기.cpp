#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    fill_n(dp, 1000001, 1000001);
    int answer = 0;
    dp[x] = 0;
    
    for(int i = x; i < y; i++){
        if(dp[i] == 1000001)
            continue;
        
        for(int j = 0; j < 3; j++){
            int nx;
            switch(j){
                case 0:
                    nx = i + n;
                    break;
                case 1:
                    nx = 2 * i;
                    break;
                case 2:
                    nx = 3 * i;
                    break;
            }
            if(nx > y)
                continue;
            dp[nx] = min(dp[nx], dp[i] + 1);
        }
    }
    answer = dp[y] != 1000001 ? dp[y] : -1;
    return answer;
}
