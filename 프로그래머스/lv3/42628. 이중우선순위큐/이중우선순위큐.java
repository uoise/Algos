import java.util.SortedMap;
import java.util.TreeMap;

class Solution {

    public int[] solution(String[] operations) {
        SortedMap<Integer, Integer> dq = new TreeMap<>();
        for (String op : operations) {
            int i = Integer.parseInt(op.substring(2));
            if (op.charAt(0) == 'I') {
                dq.put(i, dq.getOrDefault(i, 0) + 1);
            } else {
                if (dq.isEmpty()) continue;
                int key = op.charAt(2) == '-' ? dq.firstKey() : dq.lastKey();
                int val = dq.get(key);
                if (val == 1) dq.remove(key);
                else dq.put(key, val - 1);
            }
        }
        if (dq.isEmpty()) return new int[]{0, 0};
        return new int[]{dq.lastKey(), dq.firstKey()};
    }
}