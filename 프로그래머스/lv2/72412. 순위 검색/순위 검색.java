import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    static int getL(final char l) {
        if (l == 'c') return 1;
        if (l == 'j') return 2;
        if (l == 'p') return 3;
        return 0;
    }

    static int getJ(final char j) {
        if (j == 'b') return 1;
        if (j == 'f') return 2;
        return 0;
    }

    static int getO(final char o) {
        if (o == 'j') return 1;
        if (o == 's') return 2;
        return 0;
    }

    static int getF(final char f) {
        if (f == 'c') return 1;
        if (f == 'p') return 2;
        return 0;
    }

    static int lowerBound(List<Integer> v, int t) {
        int begin = 0;
        int end = v.size();
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (v.get(mid) >= t) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }

        return end;
    }

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        List<Integer>[][][][] db = new List[4][3][3][3];
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 3; b++)
                for (int c = 0; c < 3; c++)
                    for (int d = 0; d < 3; d++)
                        db[a][b][c][d] = new ArrayList<>();

        int idx = 0;
        for (String s : info) {
            String[] sr = s.split(" ");
            char l = sr[0].charAt(0);
            char j = sr[1].charAt(0);
            char o = sr[2].charAt(0);
            char f = sr[3].charAt(0);
            int v = Integer.parseInt(sr[4]);
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    for (int c = 0; c < 2; c++)
                        for (int d = 0; d < 2; d++)
                            db[a > 0 ? getL(l) : 0][b > 0 ? getJ(j) : 0][c > 0 ? getO(o) : 0][d > 0 ? getF(f) : 0].add(v);
        }

        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 3; b++)
                for (int c = 0; c < 3; c++)
                    for (int d = 0; d < 3; d++)
                        Collections.sort(db[a][b][c][d]);

        idx = 0;
        for (String q : query) {
            String[] sr = q.split(" ");
            int l = getL(sr[0].charAt(0));
            int j = getJ(sr[2].charAt(0));
            int o = getO(sr[4].charAt(0));
            int f = getF(sr[6].charAt(0));
            int v = Integer.parseInt(sr[7]);
            int lb = lowerBound(db[l][j][o][f], v);
            answer[idx++] = db[l][j][o][f].size() - lb;
        }

        return answer;
    }
}