class Solution {
    public static String[] sr = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    public static int[] ir = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    public String solution(int a, int b) {
        return sr[(ir[a - 1] + b - 1) % 7];
    }
}