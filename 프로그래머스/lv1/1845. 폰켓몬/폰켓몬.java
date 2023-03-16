import java.util.Arrays;

class Solution {
    public int solution(int[] nums) {
        return (int) Arrays.stream(nums).distinct().limit(nums.length / 2).count();
    }
}