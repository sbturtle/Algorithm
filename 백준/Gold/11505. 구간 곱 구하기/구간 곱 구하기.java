import java.io.*;
import java.util.*;

class Main {

	static final int mod = 1_000_000_007;
	static int n, m, len = 1;

	static int[] arr;
	static long[] tree;

	static void update(int idx, int v) {
		tree[idx] = v;
		while (idx > 1) {
			idx /= 2;
			tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % mod;
		}
	}

	static long get(int idx, int s, int e, int ts, int te) {
		if (s > te || e < ts)
			return 1;
		if (ts <= s && e <= te)
			return tree[idx];

		int md = (s + e) / 2;

		long l = get(idx * 2, s, md, ts, te);
		long r = get(idx * 2 + 1, md + 1, e, ts, te);

		return (l * r) % mod;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());
		m += Integer.parseInt(stt.nextToken());

		arr = new int[n];

		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		while (len < n)
			len <<= 1;

		tree = new long[2 * len];
		Arrays.fill(tree, 1);

		for (int i = 0; i < n; i++) {
			tree[len + i] = arr[i];
		}

		for (int i = len - 1; i > 0; i--) {
			tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % mod;
		}

		for (int i = 0; i < m; i++) {
			stt = new StringTokenizer(br.readLine());

			int oper = Integer.parseInt(stt.nextToken());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());

			if (oper == 1) {
				update(len + a - 1, b);
			} else {
				long result = get(1, 0, len - 1, a - 1, b - 1);
				sb.append(result).append('\n');
			}
		}

		System.out.println(sb);
	}
}
