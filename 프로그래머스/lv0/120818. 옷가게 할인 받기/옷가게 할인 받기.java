class Solution {
    public int solution(int price) {
        return price < 100000 ? price
                : price < 300000 ? price * 95 / 100
                : price < 500000 ? price * 90 / 100
                : price * 80 / 100;
    }
}