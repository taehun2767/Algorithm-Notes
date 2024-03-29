class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(const auto& num : nums) _xor ^= num;
        
        int idx = 0;
        for(int i = 0; i < 32; i++){
            if(((_xor >> i) & 1) == 1){
                idx = i;
                break;
            }
        }

        int xor1 = 0;
        int xor2 = 0;
        for(const auto& num : nums){
            if(((num >> idx) & 1) == 1) xor1 ^= num;
            else xor2 ^= num;
        }

        return {xor1, xor2};
    }
};
