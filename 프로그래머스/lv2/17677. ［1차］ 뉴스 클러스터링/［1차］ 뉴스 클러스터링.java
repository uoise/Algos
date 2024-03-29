class Solution {
    public static int[][][] ctr = new int[26][26][2];

    public int prs(String s, int pos) {
        int cnt = 0;
        char c1, c2;
        for (int i = 1; i < s.length(); i++) {
            c1 = s.charAt(i - 1);
            c2 = s.charAt(i);
            if (Character.isAlphabetic(c1) && Character.isAlphabetic(c2)) {
                c1 = Character.toLowerCase(c1);
                c2 = Character.toLowerCase(c2);
                ++ctr[c1 - 'a'][c2 - 'a'][pos];
                ++cnt;
            }
        }
        return cnt;
    }

    public int solution(String str1, String str2) {
        int max, dup = 0;
        max = prs(str1, 0);
        max += prs(str2, 1);
        for(int i = 0; i < ctr.length; i++) 
            for(int j = 0; j < ctr[i].length; j++)
                dup += Math.min(ctr[i][j][0], ctr[i][j][1]);
        

        return max == 0 ? 65536 : (int) (dup * 65536D / (max - dup));
    }
}