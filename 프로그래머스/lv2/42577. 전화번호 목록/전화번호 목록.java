import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public static final Set<String> set = new HashSet<>();

    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book, Comparator.comparingInt(String::length));
        for (String p : phone_book) {
            for (int i = 1; i < p.length(); i++) if (set.contains(p.substring(0, i))) return false;
            set.add(p);
        }
        return true;
    }
}