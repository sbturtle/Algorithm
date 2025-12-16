import java.io.*;
import java.util.*;

public class Main {

	static int n, m;
	
	static int[] dist;	
	static List<int[]>[] graph;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt;

		stt = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());

		graph = new ArrayList[n + 1];

		for (int i = 1; i <= n; i++)
			graph[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());
			int c = Integer.parseInt(stt.nextToken());

			graph[a].add(new int[] { b, c });
			graph[b].add(new int[] { a, c });
		}

		stt = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(stt.nextToken());
		int t = Integer.parseInt(stt.nextToken());

		dist = new int[n + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);

		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[0], o2[0]));

		dist[s] = 0;
		pq.offer(new int[] { 0, s });

		while (!pq.isEmpty()) {
			int[] cur = pq.poll();
			int cost = cur[0];
			int now = cur[1];

			if (dist[now] < cost)
				continue;

			for (int[] nxt : graph[now]) {
				int next = nxt[0];
				int nextCost = cost + nxt[1];

				if (dist[next] > nextCost) {
					dist[next] = nextCost;
					pq.offer(new int[] { nextCost, next });
				}
			}
		}

		System.out.println(dist[t]);
	}
}
