class Solution {
    final static int[] value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    final static String[] roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; num > 0; i++){
            while (value[i] <= num) {
                sb.append(roman[i]);
                num -= value[i];
            }
        }

        return sb.toString();
    }
}
