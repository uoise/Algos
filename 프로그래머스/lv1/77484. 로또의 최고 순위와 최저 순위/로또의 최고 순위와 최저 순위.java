import java.util.HashSet;
import java.util.Set;

class Solution {
    public static final Set<Integer> set = new HashSet<>();

    public int[] solution(int[] lottos, int[] win_nums) {
        int suc = 0, zrc = 0;
        for (int w : win_nums) set.add(w);
        for (int l : lottos) {
            if (l == 0) ++zrc;
            else if (set.contains(l)) ++suc;
        }
        return new int[]{suc + zrc > 1 ? 7 - (suc + zrc) : 6, suc > 1 ? 7 - suc : 6};
    }
}