#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }
    
    double sum = 0;
    vector<int> opinions;

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        opinions.push_back(num);
    }

    sort(opinions.begin(), opinions.end());

     int excludeNum = (int) round(0.15 * n);

     for(int j = excludeNum; j < n - excludeNum; j++){
         sum += opinions[j];
     }


     int answer = (int) round(sum / (n - 2 * excludeNum));

     cout << answer << endl;
}
