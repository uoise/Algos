class Solution {
    public String solution(String s, String skip, int index) {
        StringBuilder lst = new StringBuilder();
        for (int i = 0; i < 26; i++)
            if (skip.indexOf(('a' + i)) == -1)
                lst.append((char) ('a' + i));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++)
            sb.append(lst.charAt((lst.indexOf(String.valueOf(s.charAt(i))) + index) % lst.length()));
        return sb.toString();
    }
}