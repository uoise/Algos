import java.util.HashSet;
import java.util.Set;

class Solution {
    public int solution(String dirs) {
        Set<String> set = new HashSet<>();
        int y = 0, x = 0;
        for (char d : dirs.toCharArray()) {
            int ny = y, nx = x;
            switch (d) {
                case 'U' -> ny++;
                case 'R' -> nx++;
                case 'D' -> ny--;
                case 'L' -> nx--;
            }
            if (ny < -5 || ny > 5 || nx < -5 || nx > 5) continue;
            if (y < ny || x < nx) set.add(String.format("%d,%d %d,%d", ny, nx, y, x));
            else set.add(String.format("%d,%d %d,%d", y, x, ny, nx));
            y = ny;
            x = nx;
        }
        return set.size();
    }
}