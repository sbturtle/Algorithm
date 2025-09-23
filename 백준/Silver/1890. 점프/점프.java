import java.io.*;
import java.util.*;

public class Main {

	static int n;

	static int[] dx = { 1, 0 };
	static int[] dy = { 0, 1 };

	static int[][] arr;
	static long[][] dp;

	static void func(int x, int y) {
		for (int i = 0; i < 2; i++) {
			int nx = x;
			int ny = y;
			nx += dx[i] * arr[x][y];
			ny += dy[i] * arr[x][y];

			if (nx > n || ny > n)
				continue;

			dp[nx][ny] += dp[x][y];
		}

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		n = Integer.parseInt(br.readLine());

		arr = new int[n + 1][n + 1];
		dp = new long[n + 1][n + 1];

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 0 || dp[i][j] == 0)
					continue;
				func(i, j);
			}
		}

		System.out.println(dp[n][n]);

	}
}