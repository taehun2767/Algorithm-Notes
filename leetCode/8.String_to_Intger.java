class Solution {
    public int myAtoi(String s) {
        int i = 0; int n = s.length();
        while(i < n && s.charAt(i) == ' '){
            i++;
        }
        if (i == n) return 0;

        long number = 0;
        int sign = 1;

        if (s.charAt(i) == '-') {
            sign = -1;
            i++;
        }
        else if (s.charAt(i) == '+') i++;

        while (i < n) {
            if (Character.isDigit(s.charAt(i)) == false) break;

            number = 10 * number + (s.charAt(i) - '0');
            if (number > Integer.MAX_VALUE && sign == 1) return Integer.MAX_VALUE;
            if (number > Integer.MAX_VALUE && sign == -1) return Integer.MIN_VALUE;
            i++;
        }

        return (int) (sign * number);
    }
}
