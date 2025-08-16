import java.io.*;
import java.util.*;

class Node {
	int x, y;

	public Node(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static int[] dx = { 0, 1, 1 };
	static int[] dy = { 1, 1, 0 };

	static int n, result;
	static int[][] map;

	static void func(int dir, int x, int y) {
		if (x == n - 1 && y == n - 1) {
			result++;
			return;
		}

		int st = 0, ed = 2;
		if (dir == 0) {
			ed = 1;
		} else if (dir == 2) {
			st = 1;
		}

		f: for (int i = st; i <= ed; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny >= n)
				continue;
			if (i == 1) {
				for (int j = 0; j < 3; j++) {
					int mx = dx[j] + x;
					int my = dy[j] + y;

					if (map[mx][my] == 1)
						continue f;
				}
			} else if (map[nx][ny] == 1)
				continue;

			func(i, nx, ny);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());

		map = new int[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		func(0, 0, 1);

		System.out.print(result);
	}
}
