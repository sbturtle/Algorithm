import java.util.*;
import java.io.*;

class Solution {

	static int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	static int result, n;
	static char[][] map;

	static boolean check(int x, int y) {
		for (int i = 0; i < 8; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[nx][ny] == '*')
				return false;
		}
		return true;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			sb.append('#').append(test_case).append(' ');

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());

			result = 0;

			map = new char[n][n];

			for (int i = 0; i < n; i++) {
				map[i] = br.readLine().toCharArray();
			}

			Queue<int[]> q = new ArrayDeque<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] != '.')
						continue;
					if (!check(i, j))
						continue;

					result++;
					q.offer(new int[] { i, j });
					map[i][j] = 'f';
					while (!q.isEmpty()) {
						int[] cur = q.poll();
						for (int dir = 0; dir < 8; dir++) {
							int nx = dx[dir] + cur[0];
							int ny = dy[dir] + cur[1];

							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
								continue;

							if (map[nx][ny] != '.')
								continue;
							map[nx][ny] = 'f';

							if (!check(nx, ny))
								continue;

							q.offer(new int[] { nx, ny });
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == '.')
						result++;
				}
			}

			sb.append(result).append('\n');
		}

		System.out.println(sb);
	}
}