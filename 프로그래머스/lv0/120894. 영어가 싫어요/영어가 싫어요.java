enum Sti {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE;
}

class Solution {
    public long solution(String numbers) {
        long answer = 0;
        while (numbers.length() > 0) {
            answer *= 10;
            for (Sti s : Sti.values()) {
                if (numbers.startsWith(s.toString().toLowerCase())) {
                    answer += s.ordinal();
                    System.out.println(s.toString().toLowerCase() + " " + answer);
                    numbers = numbers.substring(s.toString().length());
                    break;
                }
            }
        }
        return answer;
    }
}