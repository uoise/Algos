import java.util.stream.Collectors;

class Solution {
    public String solution(String s, int n) {
        return s.chars().mapToObj(i -> String.valueOf((char) (i == ' ' ? i :
                Character.isLowerCase((char) i) ?
                        ((i - 'a' + n) % 26 + 'a') : ((i - 'A' + n) % 26 + 'A')))
        ).collect(Collectors.joining());
    }
}