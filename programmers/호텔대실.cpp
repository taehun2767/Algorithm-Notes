#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct comp {
     bool operator()(vector<string> a, vector<string> b){
        return a[1] > b[1];
    }
};

bool asc(vector<string> a, vector<string> b){
        return a[0] < b[0];
}

int toInt(char c){
    return c - '0';
}

bool roomAvailable(string start, string end){
    int first = 600 * toInt(start[0]) + 60 * toInt(start[1]) + 10 * toInt(start[3]) + toInt(start[4]);
    int second = 600 * toInt(end[0]) + 60 * toInt(end[1]) + 10 * toInt(end[3]) + toInt(end[4]) + 10;
    return first >= second;
}


int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<vector<string>, vector<vector<string>>, comp> pq;
    sort(book_time.begin(), book_time.end(), asc);
    for(auto t : book_time){
        if(pq.empty()){
            pq.push(t);
            continue;
        }
        if(roomAvailable(t[0], pq.top()[1])){
            pq.pop();
            pq.push(t);
        }
        else{
            pq.push(t);
        }
    }
    
    return pq.size();
}
