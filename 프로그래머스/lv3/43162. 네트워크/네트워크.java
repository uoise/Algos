import java.util.HashSet;
import java.util.Set;

class Solution {
    static int fnd(int x, int[] arr) {
        if (arr[x] == x) return x;
        return arr[x] = fnd(arr[x], arr);
    }

    static boolean union(int x, int y, int[] arr) {
        x = fnd(x, arr);
        y = fnd(y, arr);
        if (x == y) return false;
        arr[Math.max(x, y)] = Math.min(x, y);
        return true;
    }

    public int solution(int n, int[][] computers) {
        int[] group = new int[n];
        for (int i = 0; i < n; i++) group[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && computers[i][j] == 1) union(i, j, group);
        Set<Integer> answer = new HashSet<>();
        for (int g : group) answer.add(fnd(g, group));
        return answer.size();
    }
}