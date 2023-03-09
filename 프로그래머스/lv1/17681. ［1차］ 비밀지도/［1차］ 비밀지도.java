class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        StringBuilder sb;
        String[] answer = new String[n];
        for (int i = 0; i < n; i++) {
            int x = arr1[i] | arr2[i], t = n;
            sb = new StringBuilder();
            while (t-- > 0) {
                sb.append(x % 2 == 1 ? '#' : ' ');
                x /= 2;
            }
            answer[i] = sb.reverse().toString();
        }
        return answer;
    }
}