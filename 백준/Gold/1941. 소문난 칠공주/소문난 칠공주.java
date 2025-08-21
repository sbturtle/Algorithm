import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static char[][] map;

	static boolean[] c;

	static int result;

	static boolean sCheck() {
		int cnt = 0;
		for (int i = 0; i < 25; i++) {
			if (!c[i])
				continue;

			if (map[i / 5][i % 5] == 'S')
				cnt++;

			if (cnt > 3)
				return true;
		}

		return false;
	}

	private static boolean isConnect() {
		boolean[] visited = new boolean[25];
		Queue<Integer> q = new ArrayDeque<>();

		// 시작 노드 찾기
		int start = -1;
		for (int i = 0; i < 25; i++) {
			if (c[i]) {
				start = i;
				break;
			}
		}
		if (start == -1)
			return false;

		q.add(start);
		visited[start] = true;
		int count = 1;

		while (!q.isEmpty()) {
			int cur = q.poll();
			int x = cur / 5;
			int y = cur % 5;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
					continue;
				int ni = nx * 5 + ny;
				if (c[ni] && !visited[ni]) {
					visited[ni] = true;
					q.add(ni);
					count++;
				}
			}
		}

		return count == 7;
	}

	static void func(int idx, int total) {
		if (total == 7) {
			if (sCheck() && isConnect())
				result++;
			return;
		}

		for (int i = idx; i < 25; i++) {
			c[i] = true;
			func(i + 1, total + 1);
			c[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		c = new boolean[25];
		map = new char[5][5];

		for (int i = 0; i < 5; i++) {
			char[] ch = br.readLine().toCharArray();
			for (int j = 0; j < 5; j++) {
				map[i][j] = ch[j];
			}
		}

		func(0, 0);

		System.out.println(result);
	}
}
