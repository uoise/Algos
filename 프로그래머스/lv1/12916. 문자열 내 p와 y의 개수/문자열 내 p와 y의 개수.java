class Solution {
    boolean solution(String s) {
        return s.toLowerCase().chars().filter(c -> c == 'p').count() ==
                s.toLowerCase().chars().filter(c -> c == 'y').count();
    }
}