import java.util.stream.Collectors;

class Solution {
    public String solution(String my_string) {
        return my_string.chars().mapToObj(c -> String.valueOf((char) (Character.isLowerCase(c) ? Character.toUpperCase(c) : Character.toLowerCase(c)))).collect(Collectors.joining());
    }
}