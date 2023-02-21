class Solution {
    public static String[] ops = {" - ", " + "};

    public String[] solution(String[] quiz) {
        String[] res = new String[quiz.length];
        boolean neg;
        int opi = 0, eqi, lhs, rhs, idx = 0;
        for (String q : quiz) {
            neg = false;
            for (String p : ops) {
                opi = q.indexOf(p);
                if (opi > 0) break;
                if (ops[0].equals(p)) neg = true;
            }
            eqi = q.indexOf(" = ");
            lhs = Integer.parseInt(q.substring(0, opi));
            lhs += (Integer.parseInt(q.substring(opi + 3, eqi)) * (neg ? 1 : -1));
            rhs = Integer.parseInt(q.substring(eqi + 3));
            res[idx++] = lhs == rhs ? "O" : "X";
        }
        return res;
    }
}