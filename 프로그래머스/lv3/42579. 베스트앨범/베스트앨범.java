import java.util.*;
import java.util.stream.Collectors;

class Solution {

    static class Igp implements Comparable<Igp> {
        int idx;
        String genre;
        int plays;

        public String getGenre() {
            return genre;
        }

        public int getPlays() {
            return plays;
        }

        public Igp(int idx, String genre, int plays) {
            this.idx = idx;
            this.genre = genre;
            this.plays = plays;
        }

        @Override
        public int compareTo(Igp o) {
            return plays == o.plays ? idx - o.idx : plays - o.plays;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> answer = new ArrayList<>();
        int siz = plays.length;
        Igp[] arr = new Igp[siz];
        for (int i = 0; i < siz; i++) arr[i] = new Igp(i, genres[i], plays[i]);
        Map<String, List<Igp>> map = Arrays.stream(arr).collect(Collectors.groupingBy(Igp::getGenre));
        Igp[] igps = new Igp[map.size()];
        int idx = 0;
        for (Map.Entry<String, List<Igp>> el : map.entrySet()) {
            int sum = 0;
            for (Igp t : el.getValue()) sum += t.plays;
            igps[idx++] = new Igp(0, el.getKey(), sum);
        }

        Arrays.sort(igps, Comparator.comparingInt(Igp::getPlays).reversed());

        for (Igp t : igps) {
            List<Igp> el = map.get(t.genre);
            el.sort(Comparator.comparingInt(Igp::getPlays).reversed());
            for (int i = 0; i < 2 && i < el.size(); i++) answer.add(el.get(i).idx);
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}