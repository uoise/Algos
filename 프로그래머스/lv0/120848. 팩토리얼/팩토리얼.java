class Solution {
    public int solution(int n) {
        int x = 1, r = 1;
        while(x <= n) x*=++r;
        return r-1;
    }
}