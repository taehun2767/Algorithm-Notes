class Solution {
public:
    map <int, int> dict;
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(dict.find(target-nums[i]) != dict.end())
                return vector<int> {dict[target-nums[i]], i};
            dict[nums[i]] = i;
        }

    return {-1, -1};
    }
};
