class Solution {
public:
    bool isPalindrome(int x) {
        
       long int sum = 0;
       int target = x;
        if (x < 0) return false;
        while(x > 0) {
            int rem = x %10;
            sum = sum * 10 + rem;
            x = x / 10;
        }

        return sum == target;
    }
};
