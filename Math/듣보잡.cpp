#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m, count = 0;
    string name;
    map<string, int> names;
    cin >> n >> m;


    for(int i = 0; i < n + m; i++){
        cin >> name;
        names[name]++;
        if(names[name] == 2)
            count++;
    }

    cout << count << endl;
    for(auto kvp : names){
        if (kvp.second == 2)
            cout << kvp.first << endl;
    }
}
