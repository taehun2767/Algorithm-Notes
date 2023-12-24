#include <iostream>
#include <map>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int n, m;
string site, password;
map<string, string> dict;

int main(){

    fastio();
    cin >> n >> m;
    while(n--){
        cin >> site >> password;
        dict[site] = password;
    }
    
    while(m--){
        cin >> site;
        cout << dict[site] << endl;
    }
}
