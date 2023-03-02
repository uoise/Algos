class Solution {
    public String solution(String my_string, int num1, int num2) {
        return my_string.substring(0, Math.min(num1, num2))
                + my_string.charAt(Math.max(num1, num2))
                + my_string.substring((Math.min(num1, num2)) + 1, Math.max(num1, num2))
                + my_string.charAt(Math.min(num1, num2))
                + my_string.substring(Math.max(num1, num2) + 1);
    }
}