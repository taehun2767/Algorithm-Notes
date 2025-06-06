class Solution {
    private final List<String> answer = new ArrayList<>();
    private static final Map<Character, String> map = Map.of(
        '2', "abc", '3', "def", '4', "ghi",
        '5', "jkl", '6', "mno", '7', "pqrs",
        '8', "tuv", '9', "wxyz"
    );

    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.isEmpty()) return answer;
        backtracking(digits, 0, new StringBuilder());
        return answer;
    }

    public void backtracking(String digits, int idx, StringBuilder result) {
        if (idx == digits.length()){
            answer.add(result.toString());
            return;
        }

        String letters = map.get(digits.charAt(idx));
        for (char ch: letters.toCharArray()) {
            result.append(ch);
            backtracking(digits, idx + 1, result);
            result.deleteCharAt(result.length() - 1);
        }
    }
}
