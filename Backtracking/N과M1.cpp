#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
#include <queue>

#define endl '\n'
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int MAX = 101;

int n, m;
int count = 0;
bool used[9];

vector<int> numbers;

void print(vector<int> numbers)
{
    int n = numbers.size();
    for(int i =0; i < n; i++)
    {
        if (i == n-1)
            cout<<numbers[i] <<endl;
        else
            cout<<numbers[i] <<" ";
    }
}


void solution(vector<int> numbers, bool used[], int count)
{

    if (count == m)
    {
        print(numbers);
        return ;
    }

    if (count > m)
        return;
    
    for(int i = 1; i <=n; i++)
    {
        if(used[i])
            continue;
        
        used[i] = true;
        numbers.push_back(i);
        solution(numbers, used, count + 1);
        used[i] =false;
        numbers.pop_back();
    }
}

int main()
{
    fastio()
    cin>> n >> m;

    solution(numbers, used, 0);
    return 0;
}
