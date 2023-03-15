import java.util.Stack;

class Solution {
    public int solution(String s) {
        Stack<Integer> stk = new Stack<>();
        s.chars().forEach(c -> {
                    if (!stk.empty() && stk.peek() == c) stk.pop();
                    else stk.push(c);
                }
        );
        return stk.size() > 0 ? 0 : 1;
    }
}