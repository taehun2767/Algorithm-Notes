#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer (numbers.size(), 0);
    int sz = numbers.size();
    int maxNumber = -1;
    for(int i = sz - 1; i >= 0; i--){
        if(maxNumber < numbers[i]){
            answer[i] = -1;
            maxNumber = max(maxNumber, numbers[i]);
            continue;
        }
        
        int nextNumber = -1;
        for(int j = i + 1; j < sz; j++){
            if(numbers[i] < numbers[j]){
                nextNumber = numbers[j];
                maxNumber = max(maxNumber, numbers[i]);
                break;
            }
        }
        answer[i] = nextNumber;
        
    }
    return answer;
}
