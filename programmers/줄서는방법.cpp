#include <string>
#include <vector>

using namespace std;

long long factorial[21];

void calculateFactorial(int n){
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= n; i++){
        factorial[i] = factorial[i-1] * i;
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numberList;
    for(int i = 1; i <= n; i++){
        numberList.push_back(i);
    }
    calculateFactorial(n);
    while(n > 1){
        long long idx = k / factorial[n-1];
        long long residue = k % factorial[n-1];
        if(residue == 0){
            idx -= 1;
            residue = factorial[n-1];
        }
        answer.push_back(numberList[idx]);
        numberList.erase(numberList.begin() + idx);
        k = residue;
        n -= 1;
    }
    answer.push_back(numberList[0]);
    
    
    return answer;
}
