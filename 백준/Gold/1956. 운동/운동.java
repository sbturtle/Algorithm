import java.io.*;
import java.util.*;

public class Main {

	static int INF = Integer.MAX_VALUE;
	static int v, e, result = INF;

	static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine());
		v = Integer.parseInt(stt.nextToken());
		e = Integer.parseInt(stt.nextToken());

		arr = new int[v + 1][v + 1];
		for (int i = 1; i <= v; i++) {
			Arrays.fill(arr[i], INF);
			arr[i][i] = 0;
		}

		for (int i = 0; i < e; i++) {
			stt = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(stt.nextToken());
			int b = Integer.parseInt(stt.nextToken());
			int c = Integer.parseInt(stt.nextToken());

			// a -> b
			arr[a][b] = c;
		}

		for (int k = 1; k <= v; k++) {
			for (int i = 1; i <= v; i++) {
				for (int j = 1; j <= v; j++) {
					if (i == j)
						continue;
					if (arr[i][k] == INF || arr[k][j] == INF)
						continue;

					arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}

		for (int i = 1; i <= v; i++) {
			int sum = INF;
			for (int j = 1; j <= v; j++) {
				if (i == j)
					continue;
				if (arr[i][j] == INF || arr[j][i] == INF)
					continue;

				sum = Math.min(sum, arr[i][j] + arr[j][i]);
			}
			if (result > sum)
				result = sum;
		}
		if (result == INF)
			result = -1;
		System.out.println(result);
	}
}