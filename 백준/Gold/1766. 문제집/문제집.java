import java.util.*;
import java.io.*;

public class Main {

	static int n, m;

	static List<Integer>[] problem;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt;
		StringBuilder sb = new StringBuilder();

		stt = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());
		problem = new List[n + 1];
		arr = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			problem[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());

			problem[a].add(b);
			arr[b]++;
		}

		PriorityQueue<Integer> pq = new PriorityQueue<>();

		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0)
				pq.offer(i);
		}

		while (!pq.isEmpty()) {
			int cur = pq.poll();
			for (int nxt : problem[cur]) {
				if (--arr[nxt] == 0) {
					pq.add(nxt);
				}
			}
			sb.append(cur).append(' ');
		}

		System.out.println(sb);
	}
}
