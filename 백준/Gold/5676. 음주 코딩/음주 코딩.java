import java.io.*;
import java.util.*;

public class Main {

	static int n, k, len;

	static int[] arr, tree;

	static void update(int idx, int v) {
		if (v > 0)
			v = 1;
		else if (v < 0)
			v = -1;

		int nxt = len + idx;
		tree[nxt] = v;

		while (nxt > 1) {
			nxt /= 2;
			tree[nxt] = tree[2 * nxt] * tree[2 * nxt + 1];
		}

	}

	static Integer get(int idx, int s, int e, int ts, int te) {
		if (s > te || e < ts)
			return null;
		if (ts <= s && e <= te) {
			return tree[idx];
		}

		int md = (s + e) / 2;
		Integer l = get(2 * idx, s, md, ts, te);
		Integer r = get(2 * idx + 1, md + 1, e, ts, te);
		if (l == null)
			return r;
		if (r == null)
			return l;
		if (l == 0 || r == 0)
			return 0;
		return l * r;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String input;
		while ((input = br.readLine()) != null) {
			StringTokenizer stt = new StringTokenizer(input);

			n = Integer.parseInt(stt.nextToken());
			k = Integer.parseInt(stt.nextToken());
			len = 1;

			arr = new int[n];

			stt = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				int num = Integer.parseInt(stt.nextToken());
				if (num > 0)
					arr[i] = 1;
				else if (num < 0)
					arr[i] = -1;
				else
					arr[i] = 0;
			}

			while (len < n)
				len <<= 1;

			tree = new int[len * 2];

			Arrays.fill(tree, 1);

			for (int i = 0; i < n; i++)
				tree[len + i] = arr[i];

			for (int i = len - 1; i > 0; i--)
				tree[i] = tree[2 * i] * tree[2 * i + 1];

			while (k-- > 0) {
				stt = new StringTokenizer(br.readLine());
				String ch = stt.nextToken();
				if (ch.equals("C")) {
					int idx = Integer.parseInt(stt.nextToken());
					int v = Integer.parseInt(stt.nextToken());
					update(idx - 1, v);
				} else {
					int i = Integer.parseInt(stt.nextToken());
					int j = Integer.parseInt(stt.nextToken());
					int op = get(1, 0, len - 1, i - 1, j - 1);

					if (op > 0)
						sb.append('+');
					else if (op < 0)
						sb.append('-');
					else
						sb.append(0);
				}

			}
			sb.append('\n');
		}

		System.out.println(sb);
	}
}
