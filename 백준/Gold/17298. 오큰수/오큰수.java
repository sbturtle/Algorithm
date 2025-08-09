import java.util.*;
import java.io.*;

class Main {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());

		int[] arr = new int[n];

		int[] oks = new int[n];
		Arrays.fill(oks, -1);

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Stack<Integer> s = new Stack<>();
		for (int i = n - 1; i >= 0; i--) {
			if (s.isEmpty()) {
				s.push(i);
				continue;
			}
			int cur = s.peek();
			while (arr[i] >= arr[cur]) {
				s.pop();
				if (s.isEmpty())
					break;
				cur = s.peek();
			}
			if (s.isEmpty()) {
				s.push(i);
				continue;
			}

			if (arr[i] < arr[cur]) {
				oks[i] = arr[cur];
				s.push(i);
			}

		}
		for (int i = 0; i < n; i++) {
			sb.append(oks[i]).append(" ");
		}

		System.out.println(sb.toString());
	}
}