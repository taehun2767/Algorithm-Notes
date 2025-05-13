
class Solution {
    // solution 1
    public String longestCommonPrefix(String[] strs) {
        for (int i = 0; i < strs[0].length(); i++){
            for (String s : strs) {
                if (i == s.length() || strs[0].charAt(i) != s.charAt(i))
                    return s.substring(0, i);
            }
        }

        return strs[0];
    }

    // solution 2
    public String longestCommonPrefixV2(String[] strs) {
      String prefix = strs[0];
      for (int i = 0; i < strs.length; i++){
          while(strs[i].indexOf(prefix) != 0) {
              prefix = prefix.substring(0, prefix.length() - 1);
          }
      }

      return prefix;
    }
}
