import java.io.*;
import java.util.*;

public class Main {

	static int[] dz = { 0, 0, 0, 0, 1, -1 };
	static int[] dx = { 1, 0, -1, 0, 0, 0 };
	static int[] dy = { 0, 1, 0, -1, 0, 0 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());

		int[][][] arr = new int[h][n][m];
		int[][][] isvis = new int[h][n][m];

		Queue<int[]> q = new ArrayDeque<>();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				Arrays.fill(isvis[i][j], -1);
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < m; k++) {
					arr[i][j][k] = Integer.parseInt(st.nextToken());
					if (arr[i][j][k] == 1) {
						q.offer(new int[] { i, j, k });
						isvis[i][j][k] = 0;
					}
				}
			}
		}
		int result = 0;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int i = 0; i < 6; i++) {
				int nz = cur[0] + dz[i];
				int nx = cur[1] + dx[i];
				int ny = cur[2] + dy[i];
				if (nz < 0 || nx < 0 || ny < 0 || nz >= h || nx >= n || ny >= m)
					continue;

				if (arr[nz][nx][ny] != 0)
					continue;
				if (isvis[nz][nx][ny] != -1)
					continue;
				arr[nz][nx][ny] = 1;
				isvis[nz][nx][ny] = isvis[cur[0]][cur[1]][cur[2]] + 1;
				if (result < isvis[nz][nx][ny])
					result = isvis[nz][nx][ny];
				q.offer(new int[] { nz, nx, ny });
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (arr[i][j][k] == 0 && isvis[i][j][k] == -1)
						result = -1;
				}
			}
		}

		System.out.println(result);
	}

}