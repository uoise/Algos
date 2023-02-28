import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        System.out.println(Arrays.stream(new Scanner(System.in).nextLine().split(" ")).mapToLong(Long::parseLong).sum());
    }
}