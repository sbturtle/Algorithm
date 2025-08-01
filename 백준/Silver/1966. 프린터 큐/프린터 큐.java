import java.io.*;
import java.util.*;

class Node {
	int idx;
	int rank;

	Node(int idx, int rank) {
		this.idx = idx;
		this.rank = rank;
	}
}

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(st.nextToken());

		Deque<Node> q = new ArrayDeque<>();
		while (t-- != 0) {
			q.clear();
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());

			int[] cnt = new int[10];

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				int num = Integer.parseInt(st.nextToken());
				q.add(new Node(i, num));
				cnt[num]++;
			}
			
			int p = 0;
			while (!q.isEmpty()) {
				Node cur = q.poll();
				boolean isTop = true;
				for (int i = cur.rank + 1; i <= 9; i++) {
					if (cnt[i] > 0) {
						isTop = false;
						break;
					}
				}
				if (!isTop) {
					q.add(cur);
					continue;
				}
				p++;
				cnt[cur.rank]--;
				if (m == cur.idx)
					break;

			}
			sb.append(p).append("\n");
		}

		System.out.println(sb.toString());
	}
}
