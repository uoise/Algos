class Solution {
    public String solution(String s) {
        StringBuilder ans = new StringBuilder();
        int[] arr = new int[26];
        for (int i = 0; i < s.length(); i++) arr[s.charAt(i) - 'a']++;
        for (int i = 0; i < 26; i++)
            if (arr[i] == 1) ans.append((char) ('a' + i));
        return ans.toString();
    }
}