class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder(" " + s.toLowerCase());
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == ' ' && i + 1 < sb.length() && Character.isAlphabetic(sb.charAt(i + 1)))
                sb.replace(i + 1, i + 2, String.valueOf(sb.charAt(i + 1)).toUpperCase());
        }
        return sb.substring(1);
    }
}