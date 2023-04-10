import java.util.*;

class Solution {
    class Ni {
        String header;
        String num;
        int idx;
        String tail;

        public Ni(String header, String num, int idx, String tail) {
            this.header = header;
            this.num = num;
            this.idx = idx;
            this.tail = tail;
        }

        @Override
        public String toString() {
            return header + num + tail;
        }
    }

    public void prs(int ord, String s, Map<String, List<Ni>> namespace) {
        int headEnd = -1, numEnd = -1;
        for (int i = 0; i < s.length(); i++) {
            if (headEnd < 0 && Character.isDigit(s.charAt(i))) headEnd = i;
            else if (headEnd >= 0 && numEnd < 0 && !Character.isDigit(s.charAt(i))) numEnd = i;
        }

        String header = s.substring(0, headEnd);
        String num = numEnd < 0 ? s.substring(headEnd) : s.substring(headEnd, numEnd);
        String tail = numEnd < 0 ? "" : s.substring(numEnd);

        List<Ni> list = namespace.getOrDefault(header.toLowerCase(), new ArrayList<>());
        list.add(new Ni(header, num, ord, tail));

        namespace.put(header.toLowerCase(), list);
    }

    public String[] solution(String[] files) {
        Map<String, List<Ni>> map = new TreeMap<>();
        for (int i = 0; i < files.length; i++) prs(i, files[i], map);
        String[] answer = new String[files.length];
        int idx = 0;
        for (Map.Entry<String, List<Ni>> el : map.entrySet()) {
            List<Ni> list = el.getValue();
            list.sort((o1, o2) ->
                    Integer.parseInt(o1.num) == Integer.parseInt(o2.num) ? o1.idx - o2.idx : Integer.parseInt(o1.num) - Integer.parseInt(o2.num)
            );
            for (Ni ni : list) answer[idx++] = ni.toString();
        }
        return answer;
    }
}