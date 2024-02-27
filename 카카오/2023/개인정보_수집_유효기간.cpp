#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<string, int> dict;

vector<string> split(string input, char delimeter){
    stringstream ss(input);
    string temp;
    vector<string> answer;
    while(getline(ss, temp, delimeter)){
        answer.push_back(temp);
    }
    
    return answer;
}

int convertToDays(string date){
    int year = stoi(date.substr(0, 4)) * 12 * 28;
    int month = stoi(date.substr(5, 2)) * 28;
    int day = stoi(date.substr(8, 2));
    
    return year + month + day;
}

int termToDays(string term){
    return dict[term] * 28;
}

vector<int> privaciesToDays(vector<string> privacies){
    vector<int> ret;
    for(int i = 0; i < privacies.size(); i++){
        vector<string> dayAndTerm = split(privacies[i], ' ');
        ret.push_back(convertToDays(dayAndTerm[0]) + termToDays(dayAndTerm[1]));
    }
    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayDays = convertToDays(today);
        
    for(const auto& term : terms){
        vector<string> t = split(term, ' ');
        dict[t[0]] = stoi(t[1]);
    }
    
    vector<int> privacyDays = privaciesToDays(privacies);
    
    for(int i = 0; i < privacyDays.size(); i++){
        if (todayDays >= privacyDays[i])
            answer.push_back(i+1);    }
    
    return answer;
}
