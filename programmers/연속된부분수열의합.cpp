#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int minLength = 100000000;
    vector<int> answer;
    int sz = sequence.size();
    int sum = 0;
    for(int i = 0; i < sz; i++){
        sum += sequence[i];
        for(int j = i; j < sz; j++){
            if(sum > k)
                break;
            
            if(i != j)
                sum += sequence[j];
            
            if(sum == k && j - i < minLength){
                minLength = j - i;
                answer.clear();
                answer.push_back(i);
                answer.push_back(j);
            }
        }
        sum = 0;
    }
    return answer;
}
