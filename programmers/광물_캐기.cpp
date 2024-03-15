#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>


using namespace std;

/*
곡괭이 하나 당 광물 5개

한번 사용 시작한 곡괭이는 사용할 수 없을 때까지 사용
광물은 주어진 순서대로 캐기
광산에 있는 모든 광물 캐거나 더 사용할 곡괭이 없을 때까지
picks - [dia, iron, stone]

*/
vector<int> _picks;
vector<string> _minerals;

vector<map<string, int>> dict(3, map<string, int>());
int answer = INT_MAX;

void initializeDict(){
    dict[0]["diamond"] = 1;
    dict[0]["iron"] = 1;
    dict[0]["stone"] = 1;
    dict[1]["diamond"] = 5;
    dict[1]["iron"] = 1;
    dict[1]["stone"] = 1;
    dict[2]["diamond"] = 25;
    dict[2]["iron"] = 5;
    dict[2]["stone"] = 1;
}

bool isEnd(){
    for(int i = 0; i < 3; i++){
        if(_picks[i] != 0) return false;
    }
    return true;
}

void backtracking(int idx, int pirodo){
    
    if(isEnd() || idx >= _minerals.size()){
        answer = min(answer, pirodo);
        return;
    }
    
    for(int i = 0; i < 3; i++){
        if(_picks[i] == 0) continue;
        
        _picks[i]--;
        int idxTmp = idx;
        int pirodoTmp = pirodo;
        while(idxTmp < idx + 5 && idxTmp < _minerals.size()){
            pirodoTmp += dict[i][_minerals[idxTmp++]];
        }
        backtracking(idxTmp, pirodoTmp);
        _picks[i]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    initializeDict();
    _picks = picks;
    _minerals = minerals;
    
    backtracking(0, 0);
    
    return answer;
}
