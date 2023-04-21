class Solution {
    public int[] solution(int[] arr, int[] query) {
        int l = 0, r = arr.length;
        for (int i = 0; i < query.length; i++) {
            if (i % 2 == 1) l += query[i];
            else r -= ((r - l) - query[i]);
        }
        if (l >= r) return new int[]{-1};
        int[] answer = new int[r - l];
        for (int i = l; i < r; i++) answer[i - l] = arr[i];
        return answer;
    }
}