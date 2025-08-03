import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[][] std = new int[2][7];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			// 0 여학생, 1남학생
			int s = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			std[s][y]++;
		}

		int result = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= 6; j++) {
				result += std[i][j] / k;
				if (std[i][j] % k != 0) {
					result++;
				}
			}
		}
		System.out.println(result);
	}
}
