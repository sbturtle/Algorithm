import java.io.*;
import java.util.*;

public class Main {

	static int n, m;

	static int[] arr;
	static List<Integer>[] list;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());

		arr = new int[n + 1];
		list = new List[n + 1];

		for (int i = 1; i <= n; i++)
			list[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());

			arr[b]++;
			list[a].add(b);
		}

		Queue<Integer> q = new ArrayDeque<Integer>();

		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) {
				q.add(i);
			}
		}

		while (!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur).append(' ');
			for (int nxt : list[cur]) {
				arr[nxt]--;
				if (arr[nxt] == 0) {
					q.add(nxt);					
				}
			}
		}

		System.out.println(sb);
	}
}
