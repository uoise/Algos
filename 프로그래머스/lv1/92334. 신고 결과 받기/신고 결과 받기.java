import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Arrays.fill(answer, 0);

        Map<String, Integer> stoiMap = new HashMap<>();
        for (int i = 0; i < id_list.length; i++) stoiMap.put(id_list[i], i);

        List<Set<Integer>> usrLogSet = new ArrayList<>();
        for (int i = 0; i < id_list.length; i++) usrLogSet.add(new HashSet<>());
        for (String rpt : report) {
            String[] srr = rpt.split(" ");
            usrLogSet.get(stoiMap.get(srr[1])).add(stoiMap.get(srr[0]));
        }

        for (Set<Integer> usrBanLog : usrLogSet)
            if (usrBanLog.size() >= k)
                for (Integer rcv : usrBanLog) answer[rcv]++;


        return answer;
    }
}