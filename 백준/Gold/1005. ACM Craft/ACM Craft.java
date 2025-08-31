import java.io.*;
import java.util.*;

public class Main {
	static int n, k, w;
	static int[] arr;
	static int[] result;
	static List<Integer>[] rel;
	static int[] indegree;
	static StringBuilder sb;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			arr = new int[n + 1];
			result = new int[n + 1];
			rel = new List[n + 1];
			for (int i = 1; i <= n; i++) {
				rel[i] = new ArrayList<>();
			}
			indegree = new int[n + 1];

			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 0; i < k; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				indegree[y]++;
				rel[x].add(y);
			}

			w = Integer.parseInt(br.readLine());
			Queue<Integer> q = new ArrayDeque<>();

			for (int i = 1; i <= n; i++) {
				result[i] = arr[i];
				if (indegree[i] == 0)
					q.offer(i);
			}

			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int i : rel[cur]) {
					indegree[i]--;

					result[i] = Math.max(result[i], result[cur] + arr[i]);

					if (indegree[i] == 0)
						q.offer(i);
				}
			}
			sb.append(result[w]).append('\n');
		}

		System.out.println(sb);
	}
}
