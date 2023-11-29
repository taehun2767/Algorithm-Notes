#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long i = 0; i <= d; i += k){
        answer += (long) sqrt(1L*d*d - i * i) / k + 1;
    }
    
    return answer;
}
