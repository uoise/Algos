import java.util.stream.Collectors;

class Solution {
    public String solution(String my_string) {
        return my_string.chars().distinct().mapToObj(Character::toString).collect(Collectors.joining());
    }
}