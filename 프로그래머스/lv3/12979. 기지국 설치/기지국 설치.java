class Solution {
    public int solution(int n, int[] stations, int w) {
        final int len = w * 2 + 1;
        int answer = 0,lft = 1, rht;
        for (int station : stations) {
            rht = station - w;
            if (lft < rht) {
                answer += (rht - lft) / len + ((rht - lft) % len > 0 ? 1 : 0);
            }
            lft = station + w + 1;
        }
        if (n >= lft) answer += (n - lft + 1) / len + ((n - lft + 1) % len > 0 ? 1 : 0);
        return answer;
    }
}