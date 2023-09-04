#include <iostream>
#include <vector>

#define MAX 200

using namespace std;

int n;
int childrens[MAX];
vector<int> cache[MAX];

void insert(vector<int>& vec, int num){
    if(vec[0] >= num)
        return ;

    if(vec[vec.size()-1] < num)
    {
        vec.push_back(num);
        return ;
    }

    int i = vec.size() - 1;
    while(i > 0) {
        if (vec[i] > num && vec[i - 1] < num) {
            vec[i] = num;
            return;
        }

        if (vec[i] > num && vec[i - 1] > num)
            i--;
        else {
            break;
        }
    }
}

void solution(){
    int maxCount = 0;
    for(int i = 0; i < n; i++)
    {
        cache[i].push_back(childrens[i]);
        for(int j = i + 1; j < n; j++)
        {
            insert(cache[i], childrens[j]);
        }

        maxCount = max(maxCount, (int)cache[i].size());
    }
    cout << n - maxCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> childrens[i];
    }

    solution();
    
}
