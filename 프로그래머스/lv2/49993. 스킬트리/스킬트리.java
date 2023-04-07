import java.util.Arrays;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int[] tgt = new int[26];
        Arrays.fill(tgt, -1);
        for (int i = 0; i < skill.length(); i++) tgt[skill.charAt(i) - 'A'] = i;
        int answer = 0;
        for (String s : skill_trees) {
            int rct = 0;
            ++answer;
            for (char c : s.toCharArray()) {
                if (tgt[c - 'A'] == -1) continue;
                if (tgt[c - 'A'] > rct) {
                    --answer;
                    break;
                }
                ++rct;
            }
        }
        return answer;
    }
}