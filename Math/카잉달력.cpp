#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int t, m, n, x, y;

int gcd(int a, int b){
    int tmp;
    while(b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

void solution(int m, int n, int x, int y){
    int max = lcm(m, n);
    for(int i = x; i <= max; i += m){
        if(i % n == y){
            cout << i << endl;
            return;
        }
        if(i % n == 0 && y == n){
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        solution(m, n, x, y);
    }
}
