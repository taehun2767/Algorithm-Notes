#include <string>
#include <vector>

using namespace std;

int ret = 10000000;

int backtracking(int storey, int count){
    if(storey < 10){
        return min(storey + count, 10 - storey + 1 + count);
    }
    
    ret = min(ret, backtracking(storey / 10, count + storey % 10));
    ret = min (ret, backtracking(storey / 10  + 1, count + 10 - storey % 10));
    
    return ret;
}

int solution(int storey) {
    int answer = 0;
    answer = backtracking(storey, 0);
    return answer;
}
