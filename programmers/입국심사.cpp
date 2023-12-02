#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct info{
    long long time;
    long long lastTime;
};

struct  comp{
    bool operator()(info a, info b){
        return  a.lastTime + a.time >  b.lastTime + b.time;
    }
};


long long solution(int n, vector<int> times) {
    long long answer = 0;

    if(n < times.size()){
        sort(times.begin(), times.end());
        return times[n-1];
    }

    priority_queue<info, vector<info>, comp> pq;

    for(auto t : times){
        info cur;
        cur.lastTime = t;
        cur.time = t;
        pq.push(cur);
        n--;
    }
    while(n > 0){
        info cur = pq.top();
        pq.pop();
        cur.lastTime += cur.time;
        pq.push(cur);
        n--;
        if(n ==0)
            return cur.lastTime;
    }



    return -1;
}
