import java.util.*;
import java.util.stream.Collectors;

class Solution {
    static int[][] bv;
    static List<String> sti;
    static Deque<String> answer = new LinkedList<>();

    static boolean chk = false;

    void dfs(final String beg, int cnt) {
        answer.add(beg);
        if (cnt == 0) {
            chk = true;
            return;
        }
        final int cur = sti.indexOf(beg);
        for (int nxt = 0; nxt < sti.size(); nxt++) {
            if (bv[cur][nxt] == 0) continue;
            --bv[cur][nxt];
            dfs(sti.get(nxt), cnt - 1);
            if (chk) return;
            ++bv[cur][nxt];
        }
        if (chk) return;
        answer.pollLast();
    }

    void init(final String[][] tickets) {
        Set<String> set = new HashSet<>();
        set.add("ICN");
        for (final String[] t : tickets) set.add(t[1]);
        sti = set.stream().sorted().collect(Collectors.toList());
        bv = new int[sti.size()][sti.size()];
        for (final String[] t : tickets) bv[sti.indexOf(t[0])][sti.indexOf(t[1])]++;
    }

    public String[] solution(String[][] tickets) {
        init(tickets);
        dfs("ICN", tickets.length);
        return answer.toArray(String[]::new);
    }
}