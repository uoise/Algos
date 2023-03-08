class Solution {
    public String solution(String s) {
        StringBuilder res = new StringBuilder();
        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                idx = 0;
                res.append(s.charAt(i));
            } else {
                if (idx++ % 2 == 0) res.append(Character.toUpperCase(s.charAt(i)));
                else res.append(Character.toLowerCase(s.charAt(i)));
            }
        }
        return res.toString();
    }
}