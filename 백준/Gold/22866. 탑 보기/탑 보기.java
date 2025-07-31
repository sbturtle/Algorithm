import java.io.*;
import java.util.*;

public class Main {

	public static class Node {
		int idx;
		int h;

		public Node(int idx, int h) {
			this.idx = idx;
			this.h = h;
		}

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		int[] cnt = new int[n];
		int[] idx = new int[n];

		Arrays.fill(idx, -1);

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		Deque<Node> s = new ArrayDeque<>();

		s.push(new Node(0, arr[0]));
		for (int i = 1; i < n; i++) {
			if (s.peek().h > arr[i]) {
				cnt[i] = s.size();
				idx[i] = s.peek().idx;

				s.push(new Node(i, arr[i]));
			} else {
				while (!s.isEmpty()) {
					Node cur = s.peek();
					if (cur.h > arr[i]) {
						cnt[i] = s.size();
						idx[i] = cur.idx;
						s.push(new Node(i, arr[i]));
						break;
					}
					s.pop();
				}
				if (s.isEmpty()) {
					s.push(new Node(i, arr[i]));
				}

			}
		}

		s.clear();

		s.push(new Node(n - 1, arr[n - 1]));

		for (int i = n - 2; i >= 0; i--) {
			if (s.peek().h > arr[i]) {
				cnt[i] += s.size();
				if (idx[i] == -1)
					idx[i] = s.peek().idx;
				else {
					idx[i] = Math.abs(idx[i] - i) > Math.abs(s.peek().idx - i) ? s.peek().idx : idx[i];
				}

				s.push(new Node(i, arr[i]));
			} else {
				while (!s.isEmpty()) {
					Node cur = s.peek();
					if (cur.h > arr[i]) {
						cnt[i] += s.size();
						if (idx[i] == -1)
							idx[i] = s.peek().idx;
						else {
							idx[i] = Math.abs(idx[i] - i) > Math.abs(s.peek().idx - i) ? s.peek().idx : idx[i];
						}
						s.push(new Node(i, arr[i]));
						break;
					}
					s.pop();
				}
				if (s.isEmpty()) {
					s.push(new Node(i, arr[i]));
				}

			}
		}

		for (int i = 0; i < n; i++) {
			sb.append(cnt[i]);
			if (cnt[i] != 0) {
				sb.append(" ").append(idx[i] + 1);
			}
			sb.append("\n");
		}

		System.out.println(sb.toString());
	}

}
