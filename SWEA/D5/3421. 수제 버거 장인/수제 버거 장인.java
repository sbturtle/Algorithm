import java.util.*;
import java.io.*;

public class Solution {

	static boolean[][] unfit;
	static boolean[] isvis;
	static int result;
	static int n;

	static void func(int parent, int idx) {
		f: for (int i = idx; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!isvis[j])
					continue;
				if (unfit[j][i])
					continue f;
			}

			result++;
			isvis[i] = true;
			func(i, i + 1);
			isvis[i] = false;
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {
			sb.append("#").append(test_case).append(" ");

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken()); // 궁합이 맞지 않는 재료쌍

			isvis = new boolean[n + 1];
			unfit = new boolean[n + 1][n + 1];

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				unfit[a][b] = true;
				unfit[b][a] = true;
			}

			result = 1;
			func(0, 1);
			sb.append(result).append("\n");
		}
		System.out.println(sb.toString());
	}
}
