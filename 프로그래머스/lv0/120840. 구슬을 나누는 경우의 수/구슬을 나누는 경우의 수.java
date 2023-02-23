class Solution {
    public int solution(int balls, int share) {
        long res = 1;
        if (share > balls - share) share = balls - share;
        for (int i = 0; i < share; i++) {
            res *= (balls - i);
            res /= (i + 1);
        }
        return (int) res;
    }

}