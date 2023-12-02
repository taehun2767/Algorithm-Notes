#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = n * (long long)times.back();

    

    while(min <= max){
        long long mid = (min + max ) / 2 ;
        
        long long avg = 0;
    
        for(auto t : times){
            avg += mid / (long long)t;
        }
        
        if (avg >= n){
            max = mid - 1;
            answer = mid;
        }
        else
            min = mid + 1;

    }
    
    return answer;

}
