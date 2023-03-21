import java.util.PriorityQueue;

class Solution {
    public static PriorityQueue<Integer> q = new PriorityQueue<>();

    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        for (int i = 0; i < score.length; i++) {
            q.add(score[i]);
            if (q.size() > k) q.remove();
            answer[i] = q.element();
        }
        return answer;
    }
}