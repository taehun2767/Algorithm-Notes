class Solution {
    private final List<String> answer = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        backtrack(0, 0, n, new StringBuilder());
        return answer;
    }

    private void backtrack(int open, int close, int n, StringBuilder result) {
        if (open == n && close == n) {
            answer.add(result.toString());
            return;
        }

        if (open < n) {
            result.append('(');
            backtrack(open + 1, close, n, result);
            result.deleteCharAt(result.length() - 1);
        }

        if (close < open) {
            result.append(')');
            backtrack(open, close + 1, n, result);
            result.deleteCharAt(result.length() - 1);
        }
    }
}
