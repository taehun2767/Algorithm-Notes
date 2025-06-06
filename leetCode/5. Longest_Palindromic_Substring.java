class Solution {
    int start = 0;
    int end = 0;
    public void palindrom(char s[], int i) {
        int n = s.length;
        int l = i, r = i;

        if (l < 0 || r > n - 1) 
            return;
        
        while(r < n - 1 && s[r] == s[r + 1])
            r++;
        i = r;

        while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]){
            l--;
            r++;
        }

        if (end - start < r - l){
            start = l;
            end = r;
        }

        palindrom(s, i + 1);
    }

    public String longestPalindrome(String s) {
        palindrom(s.toCharArray(), 0);
        return s.substring(start, end + 1);
    }
}
