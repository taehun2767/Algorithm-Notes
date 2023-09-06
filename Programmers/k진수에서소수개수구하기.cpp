#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

//k진수 변환
string converter(int n, int k){
    string result = "";
    while(n > 0){
        int temp =  n % k;
        n = n / k;
        result += to_string(temp);
    }
    reverse(result.begin(), result.end());
    return result;
}


bool isPrime(long n){
    if(n == 1)
        return false;
    
    for(long i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

bool checkPrime(string s){
    long num = stol(s);
    return isPrime(num);
}

int solution(int n, int k) {
    int answer = 0;
    string s = converter(n, k);
    vector<string> vec = split(s, '0');

    for(auto v : vec){
        if(v == "")
            continue;
        answer += checkPrime(v);
    }

    return answer;
}
