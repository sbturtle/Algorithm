import java.util.*;
import java.io.*;

public class Main {

	static boolean[] isvis;
	static ArrayList<Integer>[] arr;
	static StringBuilder sb;

	static void dfs(int st) {
		if (isvis[st])
			return;
		isvis[st] = true;

		sb.append(st).append(" ");
		for (int i = 0; i < arr[st].size(); i++) {
			int ni = arr[st].get(i);

			if (isvis[ni])
				continue;
			dfs(ni);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());

		arr = new ArrayList[n + 1];
		isvis = new boolean[n + 1];

		for (int i = 1; i <= n; i++) {
			arr[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());

			arr[u].add(v);
			arr[v].add(u);
		}
		for (int i = 1; i <= n; i++) {
			Collections.sort(arr[i]);
		}

		dfs(start);
		sb.append("\n");

		Arrays.fill(isvis, false);
		
		Queue<Integer> q = new ArrayDeque<>();
		isvis[start] = true;
		q.offer(start);
		sb.append(start).append(" ");
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int i = 0; i < arr[cur].size(); i++) {
				int ni = arr[cur].get(i);

				if (isvis[ni])
					continue;
				isvis[ni] = true;
				sb.append(ni).append(" ");
				q.offer(ni);
			}
		}
		sb.append("\n");

		System.out.println(sb.toString());
	}
}
