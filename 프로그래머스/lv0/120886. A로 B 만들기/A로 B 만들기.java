import java.util.stream.Collectors;

class Solution {
    public int solution(String before, String after) {
        return String.valueOf(before.chars().sorted().mapToObj(i -> (char) i).collect(Collectors.toList())).equals(
                String.valueOf(after.chars().sorted().mapToObj(i -> (char) i).collect(Collectors.toList()))) ? 1 : 0;

    }
}