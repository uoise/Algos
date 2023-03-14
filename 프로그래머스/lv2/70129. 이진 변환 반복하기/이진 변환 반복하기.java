class Solution {
    public int[] solution(String s) {
        int[] answer = {0, 0};
        while (s.length() != 1) {
            answer[1] += s.length() - s.replace("0", "").length();
            s = Integer.toBinaryString((s.replace("0", "")).length());
            ++answer[0];
        }
        return answer;
    }
}