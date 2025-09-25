import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	static int n, k;
	static boolean[][] arr;
	static int[][] isvis;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		arr = new boolean[n][n];
		isvis = new int[n][n];
		for (int i = 0; i < n; i++) {
			char[] ch = br.readLine().toCharArray();
			Arrays.fill(isvis[i], -1);
			for (int j = 0; j < n; j++) {
				arr[i][j] = ch[j] == '1' ? true : false;
			}
		}

		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[2], o2[2]));
		pq.offer(new int[] { 0, 0, 0 });
		isvis[0][0] = 0;
		w: while (!pq.isEmpty()) {
			int[] cur = pq.poll();
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + cur[0];
				int ny = dy[i] + cur[1];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (isvis[nx][ny] != -1 && isvis[nx][ny] >= cur[2])
					continue;

				isvis[nx][ny] = cur[2] + (arr[nx][ny] ? 0 : 1);
				if (nx == n - 1 && ny == n - 1)
					break w;

				pq.offer(new int[] { nx, ny, isvis[nx][ny] });
			}
		}

		System.out.println(isvis[n - 1][n - 1]);
	}
}
