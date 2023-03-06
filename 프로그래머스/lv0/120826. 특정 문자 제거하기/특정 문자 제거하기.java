import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(String my_string, String letter) {
        return Arrays.stream(my_string.split("")).filter(s -> !s.equals(letter)).collect(Collectors.joining());
    }
}