class Solution {
    public boolean solution(String s) {
        return s.chars().filter(Character::isAlphabetic).count() <= 0 && (s.length() == 4 || s.length() == 6);
    }
}