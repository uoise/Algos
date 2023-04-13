import java.util.ArrayDeque;
import java.util.Queue;
import java.util.stream.Collectors;

class Solution {
    private static final char[] cv = {'A', 'E', 'I', 'O', 'U'};
    private static Queue<String> lst = new ArrayDeque<>();

    public void rcr(String s) {
        if (s.length() > 4) return;
        for (int i = 0; i < 5; i++) {
            lst.add(s + cv[i]);
            rcr(s + cv[i]);
        }
    }

    public int solution(String word) {
        rcr("");
        return lst.stream().sorted().collect(Collectors.toList()).indexOf(word) + 1;
    }
}