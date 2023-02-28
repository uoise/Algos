class Solution {

    public static String[] dcd = {
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--.."
    };

    public String solution(String letter) {
        String[] r = letter.split(" ");
        char[] res = new char[r.length];
        for (int i = 0; i < r.length; i++)
            for (int j = 0; j < dcd.length; j++)
                if (dcd[j].equals(r[i])) res[i] = (char) ('a' + j);
        return String.valueOf(res);
    }
}