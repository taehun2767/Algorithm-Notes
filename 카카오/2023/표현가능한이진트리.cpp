#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 이진수를 저장할 빈 문자열 생성
 * 더미 노드 추가하여 포화 이진트리 생성 (루트 유지)
 * 가장 왼쪽부터 오른쪽순으로
 * 노드가 더미면 문자열 뒤에 0 추가, 아닐 경우 1 추가
 * 이진수를 십진수로 변환
 * 42 ->  0101010
 * 111 -> 1101111
 */

int isPossible = 1;

string toBinary(long long number){
    string binary = "";
    while(number != 0){
        binary += to_string(number % 2);
        number /= 2;
    }
    int sz = binary.size();
    int num = 1;
    while(num < sz){
        num *= 2;
    }
    if(num > sz){
        string zeroPadding(num - sz - 1, '0');
        binary += zeroPadding;
    }
        
    reverse(binary.begin(), binary.end());
    return binary;
}

void solve(string bin, int pos, int n){
    
    if(n == 0 || isPossible == 0){
        return ;
    }
    if(bin[pos] == '1'){
        solve(bin, pos-n, n/2);
        solve(bin, pos+n, n/2);
    }
    else{
        if(bin[pos-n] == '1' || bin[pos+n] == '1'){
            isPossible = 0;
            return;
        }
        else{
            solve(bin, pos-n, n/2);
            solve(bin, pos+n, n/2);
        }
    }
    
    
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(const auto& number : numbers){
        string bin = toBinary(number);
        isPossible = 1;
        solve(bin, bin.size()/2, (bin.size()+1)/4);
        answer.push_back(isPossible);
    }
    return answer;
}
