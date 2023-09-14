#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int tidx = 0;
    int iter_idx = 0;
    int sz = truck_weights.size();
    
    queue<int> que;
    vector<int> count(sz, 0);
    
    sum += truck_weights[tidx];
    que.push(truck_weights[tidx]);
    count[tidx]++;
    iter_idx++;
    
    while(que.empty() == false){
        if(count[tidx] > bridge_length){
            que.pop();
            sum -= truck_weights[tidx];
            tidx++;
        }
        
        if(iter_idx < sz && sum + truck_weights[iter_idx] <= weight){
            sum += truck_weights[iter_idx];    
            que.push(truck_weights[iter_idx]);
            count[iter_idx]++;
            iter_idx++;
        }
        for(int i = tidx; i < iter_idx; i++){
            count[i]++;
        }
        answer++;
    }
    return answer;
}
