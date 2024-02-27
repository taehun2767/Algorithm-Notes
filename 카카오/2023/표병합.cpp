#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
/*
 * UPDATE r c value - (r,c)를 value로
 * UPDATE value1 value2 - replaceAll value1 -> value2
 * MERGE r1 c1 r2 c2 - 같은 셀: 무시, 인접 x: 두 셀만 영향, 하나만 값 가지고 있음: 그 값으로, 두 셀 모두: r1, c1꺼
 * UNMERGE r c - (r,c) 위치 셀 선택하여 모든 병합 해제, 값 있는 경우 (r,c)가 값 가짐
 * PRINT r c - 셀값 출력, 비어있는 경우 EMPTY
 */

string table[2501];
int link[2501];

int flatten(int r, int c){
    return 50 * (r-1) + c;
}

vector<string> answer;

vector<string> split(string input, char delimeter){
    
    vector<string> ret;
    string word;
    stringstream ss(input);
    while(getline(ss, word, delimeter)){
        ret.push_back(word);
    }
    
    return ret;
}

void execute(vector<string> command){
    string query = command[0];
    if(query == "UPDATE"){
        if(command.size() == 4){
            int r = stoi(command[1]);
            int c = stoi(command[2]);
            string value = command[3];
            int parent = link[flatten(r,c)];
            table[parent] = value;
        }
        else {
            string asis = command[1];
            string tobe = command[2];
            for(int i = 1; i <= 2500; i++){
                if(table[i] == asis)
                    table[i] = tobe;
            }
        }
    }
    else if (query == "MERGE"){
        int r1 = stoi(command[1]);
        int c1 = stoi(command[2]);
        int r2 = stoi(command[3]);
        int c2 = stoi(command[4]);
        
        int idx1 = flatten(r1, c1);
        int idx2 = flatten(r2, c2);
        int parent1 = link[idx1];
        int parent2 = link[idx2];
        if(parent1 != parent2){
            for(int i = 1; i <= 2500; i++){
                if(link[i] == parent2) {
                    link[i] = parent1;
                }
            }
        }
        
        if(table[parent1] != "EMPTY"){
            table[parent2] = table[parent1];
        }
        else{
            table[parent1] = table[parent2];
        }    
    }
    else if (query == "UNMERGE"){
        int r = stoi(command[1]);
        int c = stoi(command[2]);
        int idx = flatten(r, c);
        int parent = link[idx];
        string value = table[parent];
        for(int i = 1; i <= 2500; i++){
            if(link[i] == parent) {
                link[i] = i;
                table[i] = "EMPTY";
            }
        }
        table[idx] = value;
    }
    else if (query == "PRINT"){
        int r = stoi(command[1]);
        int c = stoi(command[2]);
        int idx = flatten(r,c);
        int parent = link[idx];
        string value = table[parent];


        answer.push_back(value);
    }
}

void solve(vector<string> commands){
    for(int i = 1; i <= 2500; i++){
        link[i] = i;
        table[i] = "EMPTY";
    }
    for(const auto& command : commands){
        auto c = split(command, ' ');
        execute(c);
    }
}

vector<string> solution(vector<string> commands) {
    solve(commands);
    return answer;
}
