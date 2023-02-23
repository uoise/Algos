class Solution {
    public int solution(String my_string) {
        String[] s = my_string.split(" ");
        int ans = Integer.parseInt(s[0]);
        for (int i = 1; i < s.length; i += 2)
            ans += (s[i].equals("+") ? 1 : -1) * Integer.parseInt(s[i + 1]);
        return ans;
    }
}