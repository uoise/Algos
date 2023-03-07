class Solution {
    public int[] solution(String[] wallpaper) {
        int ys = wallpaper.length;
        int xs = wallpaper[0].length();
        int[] answer = {ys + 1, xs + 1, -1, -1};
        for (int y = 0; y < ys; y++) {
            for (int x = 0; x < xs; x++) {
                if (wallpaper[y].charAt(x) == '#') {
                    answer[0] = Math.min(answer[0], y);
                    answer[1] = Math.min(answer[1], x);
                    answer[2] = Math.max(answer[2], y + 1);
                    answer[3] = Math.max(answer[3], x + 1);
                }
            }
        }
        return answer;
    }
}