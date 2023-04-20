import java.util.Arrays;

class Solution {
    public int solution(int[] num_list) {
        if (num_list.length > 10) return Arrays.stream(num_list).sum();
        int answer = 1;
        for (int n : num_list) answer *= n;
        return answer;
    }
}