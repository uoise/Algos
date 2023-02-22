class Solution {
    public static int getTime(String s) {
        int res = 0;
        String sar[] = s.split("\\.");
        res += Integer.parseInt(sar[0]) * 28 * 12;
        res += Integer.parseInt(sar[1].charAt(0) == '0' ? sar[1].substring(1) : sar[1]) * 28;
        res += Integer.parseInt(sar[2].charAt(0) == '0' ? sar[2].substring(1) : sar[2]);
        return res;
    }

    public int[] solution(String today, String[] terms, String[] privacies) {
        int tdi = getTime(today), idx = 0;
        int[] tir = new int[26];
        for (int i = 0; i < terms.length; i++)
            tir[terms[i].charAt(0) - 'A'] = Integer.parseInt(terms[i].substring(2)) * 28 - 1;

        int[] answer = new int[privacies.length];
        for (int i = 0; i < privacies.length; i++) {
            char c = privacies[i].charAt(privacies[i].length() - 1);
            int cri = getTime(privacies[i].substring(0, privacies[i].length() - 2));
            for (int j = 0; j < 26; j++) {
                if (j != c - 'A') continue;
                if (tdi > cri + tir[j]) answer[idx++] = i + 1;
            }
        }
        int[] res = new int[idx];
        for (int i = 0; i < idx; i++) res[i] = answer[i];
        return res;
    }
}