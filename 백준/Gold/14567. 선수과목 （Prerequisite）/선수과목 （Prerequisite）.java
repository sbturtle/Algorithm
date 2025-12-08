import java.io.*;
import java.util.*;

public class Main {

	static int n, m;

	static int[] result;
	static int[] depth;
	static List<Integer>[] tree;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());

		depth = new int[n + 1];
		result = new int[n + 1];

		tree = new List[n + 1];
		for (int i = 1; i <= n; i++)
			tree[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			stt = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());

			tree[a].add(b);
			depth[b]++;
		}

		Queue<int[]> q = new ArrayDeque<>();

		for (int i = 1; i <= n; i++) {
			if (depth[i] == 0) {
				q.offer(new int[] { i, 1 });
			}
		}

		while (!q.isEmpty()) {
			int[] cur = q.poll();
			result[cur[0]] = cur[1];
			for (int nxt : tree[cur[0]]) {
				depth[nxt]--;
				if (depth[nxt] == 0) {
					q.offer(new int[] { nxt, cur[1] + 1 });
				}
			}
		}

		for (int i = 1; i <= n; i++)
			sb.append(result[i]).append(' ');

		System.out.println(sb);
	}
}