#include <iostream>
#include <set>
using namespace std;

set<int> s;

void function(const string& inst,const int& num = -1){

    if(inst == "add")
        s.insert(num);
    else if(inst == "remove")
        s.erase(num);
    else if (inst == "check") {
        int check = s.find(num) != s.end();
        cout << check << "\n";
    }
    else if(inst == "toggle"){
        if(s.find(num) == s.end())
            s.insert(num);
        else
            s.erase(num);
    }
    else if(inst == "all")
        s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    else if(inst == "empty")
        s = {};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string inst;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inst;
        if(inst != "all" && inst != "empty")
            cin >> num;

        function(inst, num);
    }

}
