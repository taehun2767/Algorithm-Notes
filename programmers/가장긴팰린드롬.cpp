#include <iostream>
#include <string>

using namespace std;

int palindrome(string s, int l, int r){
    
    while(l >= 0 && r < s.size()){
        if(s[l] != s[r])
            break;
        l--;
        r++;
    }
    
    return r - l - 1;
}

int solution(string s)
{
    int oddCase = 1;
    int evenCase = 0;
    for(int i = 1; i < s.size(); i++){
        oddCase = max(oddCase, palindrome(s, i, i));
        evenCase = max(evenCase, palindrome(s, i - 1, i));
    }
    return max(oddCase, evenCase);
}
