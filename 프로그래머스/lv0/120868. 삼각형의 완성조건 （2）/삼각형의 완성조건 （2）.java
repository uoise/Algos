class Solution {
    public int swap(int a, int b) {
        return a;
    }

    public int solution(int[] sides) {
        if (sides[0] < sides[1])
            sides[0] = swap(sides[1], sides[1] = sides[0]);
        return (sides[0] + sides[1]) - (sides[0] - sides[1]) - 1;
    }
}