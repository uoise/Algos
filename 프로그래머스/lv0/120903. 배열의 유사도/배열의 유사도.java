import java.util.Arrays;
import java.util.stream.Stream;

class Solution {
    public int solution(String[] s1, String[] s2) {
        return Stream.concat(Arrays.stream(s1), Arrays.stream(s2)).toArray().length -
                Stream.concat(Arrays.stream(s1), Arrays.stream(s2)).distinct().toArray().length;
    }
}