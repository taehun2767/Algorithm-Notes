#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    int n;
    int num;
    double sum = 0;
    vector<int> numbers;
    map<int, int> dic;

    cin >> n;


    for(int i = 0; i < n; i++){
       cin >> num;
       numbers.push_back(num);
       sum += num;
       dic[num]++;
    }

    sort(numbers.begin(), numbers.end());

    vector<pair<int, int>> kvp(dic.begin(), dic.end());
    sort(kvp.begin(), kvp.end(), cmp);

    int mode;
    int sz = kvp.size();

    if(sz == 1)
        mode = kvp[sz-1].first;
    else if(kvp[sz-1].second == kvp[sz-2].second)
        mode = kvp[sz-2].first;
    else
        mode = kvp[sz-1].first;


    int roundResult = round(sum / n);
    if (roundResult == -0)
        roundResult = 0;

    cout << roundResult << endl;
    cout << numbers[n/2] << endl;
    cout << mode << endl;
    cout << numbers[n-1] - numbers[0] << endl;
}
