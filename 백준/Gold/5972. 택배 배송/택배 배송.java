import java.util.*;
import java.io.*;

public class Main {

	static int n, m;

	static List<int[]>[] list;
	static int[] dist;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());

		// st = 1, ed = n
		list = new List[n + 1];
		for (int i = 1; i <= n; i++)
			list[i] = new ArrayList<>();

		while (m-- != 0) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());
			int c = Integer.parseInt(stt.nextToken());
			list[a].add(new int[] { b, c });
			list[b].add(new int[] { a, c });
		}

		dist = new int[n + 1];
		Arrays.fill(dist, 1004 * 50_000);

		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));

		pq.add(new int[] { 1, 0 });
		dist[1] = 0;

		while (!pq.isEmpty()) {
			int[] cur = pq.poll();

			if (dist[cur[0]] < cur[1])
				continue;

			for (int[] nxt : list[cur[0]]) {
				if (dist[nxt[0]] > nxt[1] + cur[1]) {
					dist[nxt[0]] = nxt[1] + cur[1];
					pq.add(new int[] { nxt[0], dist[nxt[0]] });
				}
			}

		}

		System.out.println(dist[n]);
	}
}
