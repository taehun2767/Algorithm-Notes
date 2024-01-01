#include <iostream>
#include <queue>
#include <map>
#include <vector>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m, t, num, person, answer = 0;
bool cannotTellPerson[51], cannotTellParty[51];
queue<int> truthQue;
vector<map<int, bool>> parties;

int main(){
    fastio();
    cin >> n >> m;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> person;
        truthQue.push(person);
        cannotTellPerson[person] = true;
    }

    for(int i = 0; i < m; i++){
        map<int, bool> dic;

        cin >> num;
        for(int i = 0; i < num; i++){
            cin >> person;
            dic[person] = true;
        }

        parties.push_back(dic);
    }

    while(!truthQue.empty()){
        int knowTruthPerson = truthQue.front();
        truthQue.pop();
        for(int i = 0; i < m; i++){
            if(cannotTellParty[i])
                continue;

            if(parties[i][knowTruthPerson]){
                cannotTellParty[i] = true;
                for(const auto& kvp : parties[i]){
                    if(!cannotTellPerson[kvp.first]){
                        truthQue.push(kvp.first);
                        cannotTellPerson[kvp.first] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        if(!cannotTellParty[i])
            answer++;
    }

    cout << answer << endl;
}
