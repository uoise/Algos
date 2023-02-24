class Solution {
    public String solution(String bin1, String bin2) {
        long tmp = Long.parseLong(bin1) + Long.parseLong(bin2);
        if (tmp == 0) return "0";
        StringBuilder res = new StringBuilder();
        while (tmp > 0) {
            if (tmp % 10 > 1) tmp += 8;
            res.append(tmp % 10);
            tmp /= 10;
        }
        return res.reverse().toString();
    }
}