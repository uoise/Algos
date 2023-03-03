import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder s = new StringBuilder();
        while (n-- > 0) {
            s.append("*");
            System.out.println(s);
        }
    }
}