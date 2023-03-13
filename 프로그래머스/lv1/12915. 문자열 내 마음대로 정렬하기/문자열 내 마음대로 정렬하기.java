import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] solution(String[] strings, int n) {
        return Arrays.stream(strings).sorted(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.charAt(n) == o2.charAt(n) ? o1.compareTo(o2) : o1.charAt(n) - o2.charAt(n);
            }
        }).toArray(String[]::new);
    }
}