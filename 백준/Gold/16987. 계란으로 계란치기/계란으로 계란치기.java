import java.util.*;
import java.io.*;

class Main {
	static int n, result;
	static int[][] eggs;

	static void func(int idx, int cnt) {
		if (result < cnt)
			result = cnt;

		if (idx == n) {
			return;
		}

		for (int i = 0; i < n; i++) {
			if (idx == i)
				continue;

			int be = 0;

			boolean check = eggs[i][0] > 0 && eggs[idx][0] > 0;

			if (check) {
				eggs[i][0] -= eggs[idx][1];
				eggs[idx][0] -= eggs[i][1];

				if (eggs[idx][0] <= 0)
					be++;
				if (eggs[i][0] <= 0)
					be++;
			}

			func(idx + 1, cnt + be);

			if (check) {
				eggs[i][0] += eggs[idx][1];
				eggs[idx][0] += eggs[i][1];
			}
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		eggs = new int[n][2]; // 0: 내구도, 1: 무게

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			eggs[i][0] = Integer.parseInt(st.nextToken());
			eggs[i][1] = Integer.parseInt(st.nextToken());
		}

		func(0, 0);

		System.out.println(result);
	}
}