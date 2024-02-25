#include <string>
#include <vector>

using namespace std;

int percent[4] = {10, 20, 30, 40};
vector<int> discount;

int finalPlusCnt = 0;
int finalSalePrice = 0;

void dfs(vector<vector<int>> users, vector<int> emoticons){
    if(discount.size() == emoticons.size()){
        int plusCnt = 0;
        int priceSum = 0;
        for(const auto& user : users){
            int sum = 0;
            for(int i = 0; i < discount.size(); i++){
                if(user[0] <= discount[i]){
                    sum += emoticons[i] * (100 - discount[i]) / 100;
                }
            }
            if(user[1] <= sum){
                plusCnt++;
                sum = 0;
            }
            priceSum += sum;
        }
        
        if(plusCnt > finalPlusCnt){
            finalPlusCnt = plusCnt;
            finalSalePrice = priceSum;
        }
        else if (plusCnt == finalPlusCnt){
            finalSalePrice = max(finalSalePrice, priceSum);
        }
        
        return;
    }
    for(int i = 0; i < 4; i++){
        discount.push_back(percent[i]);
        dfs(users, emoticons);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    dfs(users, emoticons);
    return {finalPlusCnt, finalSalePrice};
}
