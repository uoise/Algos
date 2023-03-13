import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> answer = new HashSet<>();
        numbers = Arrays.stream(numbers).sorted().toArray();
        for (int i = 0; i < numbers.length; i++)
            for (int j = i + 1; j < numbers.length; j++)
                answer.add(numbers[i] + numbers[j]);
        return answer.stream().sorted().distinct().mapToInt(i -> i).toArray();
    }
}