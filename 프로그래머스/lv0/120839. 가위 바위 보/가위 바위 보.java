import java.util.stream.Collectors;

class Solution {
    public String solution(String rsp) {
        return rsp.chars().map(c -> c - '0').mapToObj(i -> String.valueOf(i == 0 ? 5 : i == 2 ? 0 : 2)).collect(Collectors.joining());
    }
}