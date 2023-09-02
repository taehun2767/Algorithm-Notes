#include <iostream>
#include <vector>

using namespace std;

int cache[101];

int n;
string s;
string word;
vector<string> words;

void solution()
{
    int sz = s.size();
    for(int i = 0; i < sz; i++)
    {
        if(i != 0 && cache[i] == 0)
            continue;

        for(int j = 0; j < n; j++)
        {
            int len = words[j].size();
            if(i + len > sz)
                continue;

            if(words[j] == s.substr(i, len))
            {
                cache[i + len] = 1;
            }

        }
    }
    cout<< cache[sz];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        words.push_back(word);
    }

    solution();

}
