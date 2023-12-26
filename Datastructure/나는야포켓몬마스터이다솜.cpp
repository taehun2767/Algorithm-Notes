#include <iostream>
#include <map>
#include <algorithm>
#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m;
string poketmon, s;
string arr[100001];
map<string, int> dic;

bool isNumber(const string &s){
    return all_of(s.begin(), s.end(), ::isdigit);
}

int main(){

    fastio();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> poketmon;
        arr[i] = poketmon;
        dic[poketmon] = i;
    }

    while(m--){
        cin >> s;
        if(isNumber(s)){
            cout << arr[stoi(s)] << endl;
        }
        else{
            cout << dic[s] << endl;
        }
    }


}
