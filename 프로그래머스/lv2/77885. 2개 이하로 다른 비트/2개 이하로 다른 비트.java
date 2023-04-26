import java.util.Arrays;

class Solution {
    public long[] solution(long[] numbers) {
        return Arrays.stream(numbers).map(i -> {
                    if (i % 2 == 0) return i + 1;
                    long t = (i + 1) & (-i);
                    return (i | t) & (~(t >> 1));
                }
        ).toArray();
    }
}