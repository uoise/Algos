import java.util.Arrays;

class Solution {
    private static final int[] iv = new int[26];

    public String solution(String[] survey, int[] choices) {
        Arrays.fill(iv, 0);

        for (int i = 0; i < survey.length; i++) {
            int c = choices[i];
            if (c == 4) continue;
            if (c < 4) iv[survey[i].charAt(0) - 'A'] += 4 - c;
            else iv[survey[i].charAt(1) - 'A'] += c - 4;
        }

        return (iv['R' - 'A'] >= iv['T' - 'A'] ? "R" : "T") +
                (iv['C' - 'A'] >= iv['F' - 'A'] ? "C" : "F") +
                (iv['J' - 'A'] >= iv['M' - 'A'] ? "J" : "M") +
                (iv['A' - 'A'] >= iv['N' - 'A'] ? "A" : "N");
    }
}