import java.util.Arrays;

class Solution {
    public int solution(int[] numbers) {
        int answer = -100000001;
        Arrays.sort(numbers);
        for(int i = 0; i < numbers.length; i++)
            for(int j = i + 1 ; j < numbers.length; j++)
                answer = Math.max(answer, numbers[i] * numbers[j]);
        return answer;
    }
}