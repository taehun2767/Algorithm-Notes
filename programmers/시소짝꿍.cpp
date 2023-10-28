#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(int a, int b){
    vector<int> mult = {2, 3, 4};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a * mult[i] == b * mult[j])
                return true;
        }
    }
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    int sz = weights.size();
    for(int i = 0; i < sz; i++){
        for(int j = i + 1; j < sz; j++){
            answer += check(weights[i], weights[j]);
        }
    }
    return answer;
}
