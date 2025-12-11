import java.io.*;
import java.util.*;

public class Main {

	static final long INF = Long.MAX_VALUE;
	static int n, m;
	static List<int[]>[] tree;
	static boolean[] ward;
	static long[] dist;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		ward = new boolean[n];
		dist = new long[n];
		Arrays.fill(dist, INF);

		tree = new ArrayList[n];
		for (int i = 0; i < n; i++)
			tree[i] = new ArrayList<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			ward[i] = st.nextToken().equals("1");

		while (m-- > 0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());

			if ((a != n - 1 && ward[a]) || (b != n - 1 && ward[b]))
				continue;

			tree[a].add(new int[] { b, t });
			tree[b].add(new int[] { a, t });
		}

		PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(o -> o[1]));
		pq.add(new long[] { 0, 0 });
		dist[0] = 0;

		while (!pq.isEmpty()) {
			long[] cur = pq.poll();
			int now = (int) cur[0];
			long cost = cur[1];

			if (dist[now] < cost)
				continue;
			if (now == n - 1)
				break;

			for (int[] nxt : tree[now]) {
				if (cost + nxt[1] < dist[nxt[0]]) {
					dist[nxt[0]] = cost + nxt[1];
					pq.add(new long[] { nxt[0], dist[nxt[0]] });
				}
			}
		}

		System.out.println(dist[n - 1] == INF ? -1 : dist[n - 1]);
	}
}
