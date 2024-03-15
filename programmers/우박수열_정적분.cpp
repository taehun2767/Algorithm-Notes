#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> y; y.reserve(10000000);
    vector<double> pSum; pSum.reserve(10000000);
    vector<double> answer;
    
    y[0] = k;
    
    int n = 0;
    while(k > 1){
        if(k % 2 == 0){
            k /= 2;
        }
        else{
            k = 3 * k + 1;
        }
        n++;
        
        y[n] = k;
        pSum[n] = pSum[n-1] + (y[n-1] + y[n]) / 2;
    }
    
    for(const auto& range : ranges){
        int s = range[0];
        int d = range[1];
        if(d <= 0)
            d = n+d;
        
        double ans = s <= d ? pSum[d] - pSum[s] : -1;
        answer.push_back(ans);
    }
    
    
    return answer;
}
