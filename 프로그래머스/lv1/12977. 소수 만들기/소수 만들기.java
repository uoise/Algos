import java.util.Arrays;

class Solution {

    public int solution(int[] nums) {
        int answer = 0;
        int max = Arrays.stream(nums).sum(), siz = nums.length;
        boolean[] pr = new boolean[max + 1];
        Arrays.fill(pr, true);
        pr[0] = pr[1] = false;
        for (int i = 2; i <= max; i++)
            if (pr[i])
                for (int j = 2; i * j <= max; j++)
                    pr[i * j] = false;
        for (int i = 0; i < siz; i++)
            for (int j = i + 1; j < siz; j++)
                for (int k = j + 1; k < siz; k++)
                    if (pr[nums[i] + nums[j] + nums[k]]) answer++;
        return answer;
    }
}