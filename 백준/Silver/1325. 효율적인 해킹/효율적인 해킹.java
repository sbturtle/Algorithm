import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		List<Integer>[] rel = new List[n + 1];

		for (int i = 0; i <= n; i++)
			rel[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());

			rel[v].add(u);
		}

		int[] isvis = new int[n + 1];
		int[] result = new int[n + 1];

		int mx = 0;
		Queue<Integer> q = new ArrayDeque<>();

		for (int i = 1; i <= n; i++) { // 전체 탐색
			isvis[i] = i;
			q.offer(i);
			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int j = 0; j < rel[cur].size(); j++) {
					int nxt = rel[cur].get(j);
					if (isvis[nxt] == i)
						continue;
					result[i]++;
					isvis[nxt] = i;
					q.offer(nxt);
				}
			}
			if (mx < result[i])
				mx = result[i];
		}

		for (int i = 1; i <= n; i++) {
			if (mx != result[i])
				continue;
			sb.append(i).append(" ");
		}

		System.out.println(sb.toString());
	}
}
