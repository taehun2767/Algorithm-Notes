#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string board[51][51];
bool merged[51][51];

vector<vector<pair<int, int>>> cache;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    for(auto command : commands){
        vector<string> line = split(command, ' ');
        if(line[0] == "UPDATE"){
            if (atoi(line[1].c_str()) != 0 || line[1].compare("0") == 0){
                int r = stoi(line[1]);
                int c = stoi(line[2]);
                string value = line[3];

                board[r][c] = value;
                if(merged[r][c] == true){
                    for(auto vec : cache){
                        auto it =find(vec.begin(), vec.end(), make_pair(r, c));
                        if(it == vec.end())
                            continue;
                        else{
                            for(auto p : vec){
                                board[p.first][p.second] = value;
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < 51; i++){
                    for(int j = 0; j < 51; j++){
                        if(board[i][j] == line[1])
                            board[i][j] = line[2];
                    }
                }
            }
        }

        else if (line[0] == "MERGE"){
            int r1 = stoi(line[1]);
            int c1 = stoi(line[2]);
            int r2 = stoi(line[3]);
            int c2 = stoi(line[4]);
            if(board[r1][c1] != ""){
                board[r2][c2] = board[r1][c1];
            }
            else if (board[r2][c2] != ""){
                board[r1][c1] = board[r2][c2];
            }
            bool flag = false;
            for(auto vec : cache){
                for(int i = 0; i < vec.size(); i++){
                    if(vec[i].first == r1 && vec[i].second == c1){
                        vec.push_back(make_pair(r2, c2));
                        flag = true;
                        break;
                    }
                    else if (vec[i].first == r2 && vec[i].second == c2){
                        vec.push_back(make_pair(r1, c1));
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(!flag){
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(r1, c1));
                temp.push_back(make_pair(r2, c2));
                cache.push_back(temp);
            }
            merged[r1][c1] = true;
            merged[r2][c2] = true;
        }

        else if (line[0] == "UNMERGE"){
            int r = stoi(line[1]);
            int c = stoi(line[2]);
            string value = board[r][c];
            for(auto vec : cache){
                auto it =find(vec.begin(), vec.end(), make_pair(r, c));
                if(it == vec.end())
                    continue;
                else{
                    for(auto p : vec){
                        board[p.first][p.second] = value;
                    }
                }
            }
        }
        else if (line[0] == "PRINT"){
            int r = stoi(line[1]);
            int c = stoi(line[2]);
            string value = board[r][c];
            answer.push_back(value);
        }

        for(int i =0 ;i <6; i++){
            for(int j = 0; j < 6; j++){
                cout << board[i][j]<<" ";
            }
            cout << endl;
        }

    }


    return answer;
}

int main(){
    vector<string> commands = {"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"};
    vector<string> commands2 = {"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"};

    auto result = solution(commands2);
    for(auto r : result)
        std::cout << r<<" ";
}
