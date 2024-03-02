#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool visited[10001];
bool flag = false;
int sz;

void dfs(string cur, int cnt){
    answer.push_back(cur);
    
    if(cnt == sz){
        flag = true;
        return;   
    }    
    
    for(int i = 0; i < ticket.size(); i++){
        if(visited[i]) continue;
        if(ticket[i][0] == cur){
            visited[i] = true;
            dfs(ticket[i][1], cnt+1);
            
            if(flag == false){
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    sz = tickets.size() + 1;
    dfs("ICN", 1);
    return answer;
}
