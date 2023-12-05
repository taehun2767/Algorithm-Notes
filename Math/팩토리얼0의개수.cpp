#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int twoCount = 0;
    int fiveCount = 0;

    for(int i = n; i > 0; i--){
        int num = i;
        while(num % 2 == 0){
            num /= 2;
            twoCount++;
        }

        while(num % 5 == 0){
            num /= 5;
            fiveCount++;
        }
    }

    cout<< min(twoCount, fiveCount);
}
