#include <iostream>
#include <vector>
#include <map>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){

    fastio();
    int t, n, ans;
    string item, category;

    cin >> t;
    while(t--){
        cin >> n;
        map<string, int> dic;
        for(int i = 0; i < n; i++){
            cin >> item >> category;
            dic[category]++;
        }

        ans = 1;
        for(const auto &kvp : dic){
            ans *= (kvp.second + 1);
        }
        cout << ans - 1 << endl;
    }
}
