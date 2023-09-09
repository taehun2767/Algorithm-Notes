#include <string>
#include <vector>
#include <iostream>

using namespace std;

int checkLeft[10001];
int checkRight[10001];

int solution(vector<int> topping) {
    int answer = 0;
    int leftCount = 0;
    int rightCount = 0;
  
    for(auto t : topping){
        if(checkRight[t] == 0)
            rightCount++;
        
        checkRight[t]++;
    }
    
    for(auto t : topping){
        if(checkLeft[t] == 0)
            leftCount++;
        
        checkLeft[t]++;
        checkRight[t]--;
        if(checkRight[t] == 0)
            rightCount--;
        
        answer += leftCount == rightCount;
    }
    
    return answer;
}
