import java.util.Arrays;
import java.util.Comparator;

class Nii {
    public int x;

    public Nii(int x) {
        this.x = x;
    }
}

class Solution {

    public int[] solution(int[] numlist, int n) {
        int[] answer = new int[numlist.length];

        Comparator<Nii> cmp = new Comparator<Nii>() {
            @Override
            public int compare(Nii o1, Nii o2) {
                return (Math.abs(n - o1.x) == Math.abs(n - o2.x)) ? (o2.x - o1.x) :
                        (Math.abs(n - o1.x) - Math.abs(n - o2.x));
            }
        };
        Nii[] arr = new Nii[numlist.length];
        for (int i = 0; i < numlist.length; i++)
            arr[i] = new Nii(numlist[i]);

        Arrays.sort(arr, cmp);

        for (int i = 0; i < numlist.length; i++)
            answer[i] = arr[i].x;
        return answer;
    }
}