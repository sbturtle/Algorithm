import java.io.*;
import java.util.*;

public class Main {

	static int[] result;
	static int[][] map;

	static boolean check(int x, int y, int size, int op) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (map[i][j] != op) {
					return false;
				}
			}
		}
		return true;
	}

	static void func(int x, int y, int size) {
		if (check(x, y, size, map[x][y])) {
			result[map[x][y] + 1]++;
			return;
		}
		int ns = size / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				func(x + (ns * i), y + (ns * j), ns);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		result = new int[3];
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		func(0, 0, n);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 3; i++) {
			sb.append(result[i]).append('\n');
		}

		System.out.println(sb);
	}

}
