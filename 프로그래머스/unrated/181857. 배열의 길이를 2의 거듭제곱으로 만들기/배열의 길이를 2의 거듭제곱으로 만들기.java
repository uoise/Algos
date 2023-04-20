import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] arr) {
        int siz = (int) Math.pow(2, Integer.toBinaryString(arr.length).length());
        if (arr.length == siz / 2) return arr;
        return IntStream.range(0, siz).map(i -> i < arr.length ? arr[i] : 0).toArray();
    }
}