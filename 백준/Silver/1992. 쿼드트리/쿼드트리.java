import java.io.*;

public class Main {

	static int[] dx = { 0, 0, 1, 1 };
	static int[] dy = { 0, 1, 0, 1 };

	static int n;
	static int[][] arr;
	static StringBuilder sb;

	static boolean check(int x, int y, int size, int wb) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (wb != arr[i][j])
					return false;
			}
		}
		return true;
	}

	static void func(int x, int y, int size) {
		if (check(x, y, size, arr[x][y])) {
			sb.append(arr[x][y]);
			return;
		}

		sb.append("(");
		int ns = size / 2;
		for (int i = 0; i < 4; i++) {
			int nx = x + (ns * dx[i]);
			int ny = y + (ns * dy[i]);
			func(nx, ny, ns);
		}
		sb.append(")");
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];

		for (int i = 0; i < n; i++) {
			char[] ch = br.readLine().toCharArray();
			for (int j = 0; j < n; j++) {
				arr[i][j] = ch[j] - '0';
			}
		}

		func(0, 0, n);

		System.out.println(sb);
	}
}
