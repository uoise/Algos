class Solution {
    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();
        while (k > 0) {
            if (k == number.length()) {
                break;
            }
            char val = '0';
            int idx = -1;
            for (int i = 0; i <= k; i++) {
                if (number.charAt(i) > val) {
                    val = number.charAt(i);
                    idx = i;
                }
            }
            k -= idx;
            number = number.substring(idx + 1);
            answer.append(val);
        }
        if (k == 0 && number.length() > 0) answer.append(number);
        return answer.toString();
    }
}