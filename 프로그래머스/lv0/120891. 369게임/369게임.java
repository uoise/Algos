class Solution {
    public int solution(int order) {
        return (int) String.valueOf(order).chars().filter(i -> i != '0' && (i - '0') % 3 == 0).count();
    }
}