import java.util.List;
import java.util.stream.Collectors;


class Solution {
    public int solution(int num, int k) {
        List<Integer> arr = String.valueOf(num).chars().map(c -> c - '0').boxed().collect(Collectors.toList());
        return arr.stream().filter(i -> i == k).map(i -> arr.indexOf(i) + 1).min(Integer::compareTo).orElse(-1);
    }
}