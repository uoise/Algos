import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public int solution(String dartResult) {
        int answer = 0, bef = 0, mul = 1, pow = 0, cur = 0;
        Pattern p = Pattern.compile("[0-9]+[D-T][*#]*");
        Pattern pn = Pattern.compile("[0-9]+");
        Pattern pb = Pattern.compile("[D-T]");
        Pattern po = Pattern.compile("[*#]");
        Matcher m = p.matcher(dartResult);
        Matcher mn, mb, mo;
        while (m.find()) {
            String s = m.group();
            mn = pn.matcher(s);
            cur = mn.find() ? Integer.parseInt(mn.group()) : 1;
            mb = pb.matcher(s);
            if (mb.find()) {
                switch (mb.group()) {
                    case "D" -> pow = 2;
                    case "S" -> pow = 1;
                    case "T" -> pow = 3;
                }
            }
            mo = po.matcher(s);
            mul = mo.find() ? (mo.group().equals("*") ? 2 : -1) : 1;
            cur = (int) Math.pow(cur, pow);
            answer += (mul > 0 ? bef * mul : bef);
            bef = cur * mul;
        }
        return answer + bef;
    }
}
