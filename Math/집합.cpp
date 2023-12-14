#include <iostream>
#include <set>
using namespace std;

int bit = 0;

void function(const string& inst,const int& num = -1){

    if(inst == "add")
        bit |= 1 << num;
    else if(inst == "remove")
        bit &= ~(1 << num);
    else if (inst == "check") {
        if(bit & (1 << num))
            cout << "1\n";
        else
            cout << "0\n";
    }
    else if(inst == "toggle"){
        if(bit & (1 << num))
            bit &= ~(1 << num);
        else
            bit |= 1<< num;
    }
    else if(inst == "all")
        bit = (1 << 21) - 1;
    else if(inst == "empty")
        bit = 0;
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
