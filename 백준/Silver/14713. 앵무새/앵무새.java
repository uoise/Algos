import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static int n;
	private static ArrayList<Queue<String>> qv;

	private static boolean sol() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		qv = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			Queue<String> q = new LinkedList<>();
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			while (st.hasMoreTokens()) q.add(st.nextToken());
			qv.add(q);
		}
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		while (st.hasMoreTokens()) {
			String w = st.nextToken();
			boolean r = false;
			for (Queue<String> c : qv) {
				if (!w.equals(c.peek())) continue;
				r = true;
				c.poll();
			}
			if (!r) return false;
		}
		for (Queue<String> q : qv) if (!q.isEmpty()) return false;
		return true;
	}

	public static void main(String[] args) throws IOException {
		System.out.println(sol() ? "Possible" : "Impossible");
	}
}