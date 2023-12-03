#include <string>
#include <vector>

using namespace std;

vector<int> pulse(vector<int> v, int num){
    for(int i = 0; i < v.size(); i++){
        v[i] = v[i]*num;
        num *= -1;
    }
    return v;
}

long long calculate(vector<int> sequence){
    long long sum = 0;
    long long maxSum = 0;
    for(int i = 0; i < sequence.size(); i++){
        sum += sequence[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    answer = calculate(pulse(sequence, 1));
    answer = max(calculate(pulse(sequence, -1)), answer);
    
    return answer;
}
