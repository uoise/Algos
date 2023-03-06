class Solution {
    public int[] solution(int[] numbers, int num1, int num2) {
        int[] ans = new int[num2 - num1 + 1];
        for (int i = num1; i <= num2; i++) ans[i - num1] = numbers[i];
        return ans;
    }
}