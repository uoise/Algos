import java.util.stream.IntStream;

class Solution {
    public int solution(String name) {
        int chg = name.chars().map(c -> c - 'A').map(i -> Math.min(i, 26 - i)).sum();
        int mov = IntStream.range(0, name.length()).filter(i -> name.charAt(i) != 'A').max().orElse(0);
        boolean chk = false;
        int lft = -1, rht;
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == 'A') {
                if (!chk) lft = i - 1;
                chk = true;
            } else {
                if (chk) {
                    rht = i;
                    int ll = Math.max(0, lft * 2) + (name.length() - rht);
                    int rr = lft + (name.length() - rht) * 2;
                    mov = Math.min(mov, Math.min(ll, rr));
                    chk = false;
                }
            }
        }
        return chg + mov;
    }
}