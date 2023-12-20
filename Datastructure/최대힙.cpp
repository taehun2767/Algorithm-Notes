#include <iostream>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, num;
priority_queue<int> pq;

int main(){

    fastio();
    cin >> n;
    while(n--){
        cin >> num;
        if(num != 0)
            pq.emplace(num);
        else
        {
            if(pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }

        }
    }
}
