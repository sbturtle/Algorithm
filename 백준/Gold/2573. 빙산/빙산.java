import java.io.*;
import java.util.*;

class Main {
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static int n, m;
	static int[][] arr;

	static int melt() {
		int[][] tmp = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) {
					int cnt = 0;
					for (int d = 0; d < 4; d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m)
							continue;
						if (arr[nx][ny] == 0)
							cnt++;
					}
					tmp[i][j] = Math.max(0, arr[i][j] - cnt);
				}
			}
		}
		arr = tmp;
		return 0;
	}

	static int countIce() {
		boolean[][] vis = new boolean[n][m];
		int cnt = 0;
		Queue<int[]> q = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0 && !vis[i][j]) {
					cnt++;
					q.offer(new int[] { i, j });
					vis[i][j] = true;
					while (!q.isEmpty()) {
						int[] cur = q.poll();
						for (int d = 0; d < 4; d++) {
							int nx = cur[0] + dx[d];
							int ny = cur[1] + dy[d];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m)
								continue;
							if (arr[nx][ny] > 0 && !vis[nx][ny]) {
								vis[nx][ny] = true;
								q.offer(new int[] { nx, ny });
							}
						}
					}
				}
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		n = Integer.parseInt(stt.nextToken());
		m = Integer.parseInt(stt.nextToken());
		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			stt = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(stt.nextToken());
			}
		}

		int year = 0;
		while (true) {
			int iceCount = countIce();
			if (iceCount >= 2)
				break;
			if (iceCount == 0) {
				year = 0;
				break;
			}
			melt();
			year++;
		}

		System.out.println(year);
	}
}
