#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int sz = numbers.size();
    vector<int> answer(sz, -1);
    stack<int> stk;
    
    for(int i = sz - 1; i >= 0; i--){
        while(true){
            if(stk.empty()){
                break;
            }
            
            if(numbers[i] < stk.top()){
                answer[i] = stk.top();
                break;
            }
            
            stk.pop();
        }
        stk.push(numbers[i]);
    }
    return answer;
}
