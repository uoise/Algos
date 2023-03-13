import java.util.Arrays;

class Solution {
    public String solution(String s) {
        return Arrays.stream(s.split(" "))
                .mapToInt(Integer::parseInt).min().orElse(0)
                + " " +
                Arrays.stream(s.split(" "))
                        .mapToInt(Integer::parseInt).max().orElse(0);
    }
}