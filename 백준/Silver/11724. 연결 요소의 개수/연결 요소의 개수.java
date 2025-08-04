import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		boolean[][] graph = new boolean[1001][1001];
		boolean[] isvis = new boolean[1001];

		Set<Integer> s = new HashSet<>();

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());

			graph[u][v] = true;
			graph[v][u] = true;

			s.add(u);
			s.add(v);
		}

		int result = 0;
		Deque<Integer> q = new ArrayDeque<>();
		for (int num : s) {
			if (isvis[num])
				continue;

			result++;
			q.clear();
			q.add(num);
			isvis[num] = true;

			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int i = 1; i <= 1000; i++) {
					if (!graph[cur][i] || isvis[i])
						continue;

					isvis[i] = true;
					q.add(i);
				}
			}
		}
		
		result += n - s.size();
		
		System.out.println(m == 0 ? n : result);
	}
}
