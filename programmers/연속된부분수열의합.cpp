#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {

    vector<int> answer;
    int sz = sequence.size();
    int minLength = sz;
    int sum = sequence[0];
    
    int s = 0;
    int e = 0;
    
    while(s <= e && e < sz){
        if(sum < k){
            sum += sequence[++e];
        }
        else if(sum == k){
            if(e - s < minLength){
                minLength = e - s;
                answer = {s, e};
            }
            else if(e -s == minLength){
                if(answer[0] > s){
                    answer = {s, e};
                }
            }
            sum -= sequence[s++];
        }
        else{

            sum -= sequence[s++];
        }
    }
    return answer;
}
