class Solution {
    public String solution(int[] food) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < food.length; i++)
            sb.append(String.valueOf(i).repeat(food[i] / 2));
        String s = sb.toString();
        return s + "0" + sb.reverse();
    }
}