#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int max = order.size();
    int box = 1;
    int idx = 0;
    stack<int> stk;
    while(true){
        if(box == order[idx]){
            box++;
            idx++;
            answer++;
            continue;
        }
        if(stk.empty() == false && stk.top() == order[idx]){
            idx++;
            stk.pop();
            answer++;
            continue;
        }
        if(box > max)
            break;
        
        stk.push(box);
        box++;
    }
    
    return answer;
}
