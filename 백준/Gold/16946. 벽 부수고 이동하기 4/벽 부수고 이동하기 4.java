import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = new int[] { 1, 0, -1, 0 };
	static int[] dy = new int[] { 0, 1, 0, -1 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		boolean[][] arr = new boolean[n][m];
		int[][] isvis = new int[n][m];
		int[][] result = new int[n][m];

		for (int i = 0; i < n; i++) {
			char[] ch = br.readLine().toCharArray();
			for (int j = 0; j < m; j++) {
				arr[i][j] = ch[j] == '1' ? true : false;
			}
			Arrays.fill(isvis[i], -1);
		}
		List<Integer> list = new ArrayList<>();

		Queue<int[]> q = new ArrayDeque<>();
		// 벽을 기준으로 갈 수 있는 칸의 수를 출력하기
		// 모든 벽에 대해 해야 하기에, 그냥 0 덩어리를 먼저 찾아, 인덱스 번호를 부여하고
		// 각 인덱스의 크기를 제공하는 것은 어떨까?
		// 그럼 각 벽별로 인접한 0의 인덱스들의 합 + 자기 자신의 크기 1로 끝날 것같은데.
        int cnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] || isvis[i][j] != -1)
					continue;
				cnt = 1;
				isvis[i][j] = list.size();
				q.offer(new int[] { i, j });

				while (!q.isEmpty()) {
					int[] cur = q.poll();
					for (int d = 0; d < 4; d++) {
						int nx = dx[d] + cur[0];
						int ny = dy[d] + cur[1];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m)
							continue;
						if (arr[nx][ny] || isvis[nx][ny] != -1)
							continue;
						isvis[nx][ny] = isvis[cur[0]][cur[1]];
						cnt++;
						q.offer(new int[] { nx, ny });
					}
				}
				list.add(cnt);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j])
					continue;
				cnt = 1;
				int[] f = new int[] { -1, -1, -1, -1 };
				outer: for (int d = 0; d < 4; d++) {
					int nx = dx[d] + i;
					int ny = dy[d] + j;
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					if (arr[nx][ny])
						continue;
					for (int k = 0; k < d; k++) {
						if (isvis[nx][ny] == f[k])
							continue outer;
					}
					f[d] = isvis[nx][ny];
					// 같은 곳에 방문은 할 수 없음
					cnt += list.get(isvis[nx][ny]);
				}

				result[i][j] = cnt % 10;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sb.append(result[i][j]);
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}