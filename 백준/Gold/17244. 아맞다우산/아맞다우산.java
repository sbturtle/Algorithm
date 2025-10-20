import java.io.*;
import java.util.*;

class Main {

	static int n, m;

	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static char[][] arr;
	static int[][][] isvis;

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		m = Integer.parseInt(stt.nextToken());
		n = Integer.parseInt(stt.nextToken());

		arr = new char[n + 1][m + 1];
		isvis = new int[n + 1][m + 1][(1 << 6) + 1];

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				Arrays.fill(isvis[i][j], -1);
			}
		}

		Queue<int[]> q = new ArrayDeque<>();
		List<int[]> list = new ArrayList<>();

		for (int i = 1; i <= n; i++) {
			char[] ch = br.readLine().toCharArray();
			for (int j = 1; j <= m; j++) {
				arr[i][j] = ch[j - 1];

				if (arr[i][j] == 'S') {
					q.offer(new int[] { i, j, 0 });
					isvis[i][j][0] = 0;
				} else if (arr[i][j] == 'X') {
					list.add(new int[] { i, j });
				}
			}
		}

		int result = -1;

		w: while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + cur[0];
				int ny = dy[i] + cur[1];

				int items = cur[2];
				if (nx < 1 || ny < 1 || nx > n || ny > m)
					continue;
				if (isvis[nx][ny][items] != -1)
					continue;
				if (arr[nx][ny] == '#')
					continue;

				if (arr[nx][ny] == 'X') {
					int idx = 0;
					for (int[] x : list) {
						if (x[0] == nx && x[1] == ny) {
							items |= 1 << idx;
							break;
						}
						idx++;
					}
				}

				isvis[nx][ny][items] = isvis[cur[0]][cur[1]][cur[2]] + 1;
				if (arr[nx][ny] == 'E' && items == (1 << list.size()) - 1) {
					result = isvis[nx][ny][items];
					break w;
				}

				q.offer(new int[] { nx, ny, items });
			}
		}

		System.out.println(result);
	}
}
