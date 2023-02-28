import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        System.out.println(Arrays.stream(new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ")).mapToLong(Long::parseLong).sum());
    }
}