class Solution {
    public long solution(int price, int money, int count) {
        return (long) count * (count + 1) / 2 * price - money < 0 ? 0 : (long) count * (count + 1) / 2 * price - money;
    }
}