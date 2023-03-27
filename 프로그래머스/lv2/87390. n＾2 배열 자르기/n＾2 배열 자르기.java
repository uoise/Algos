import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int n, long left, long right) {
        List<Integer> lst = new ArrayList<>();
        for (long i = left; i <= right; i++) lst.add((int) Math.max(i / n, i % n) + 1);
        return lst.stream().mapToInt(i -> i).toArray();
    }
}