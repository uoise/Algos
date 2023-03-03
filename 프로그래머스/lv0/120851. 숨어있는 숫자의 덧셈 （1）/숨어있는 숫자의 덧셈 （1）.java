class Solution {
    public int solution(String my_string) {
        return my_string.chars().filter(c -> !Character.isAlphabetic(c)).map(c -> c - '0').sum();
    }
}