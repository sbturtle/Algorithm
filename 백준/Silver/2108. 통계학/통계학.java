import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());

		int[] arr = new int[n];
		int[] cnt = new int[8004];

		int sum = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
			cnt[arr[i] + 4001]++;
			sum += arr[i];
		}
		Arrays.sort(arr);

		int maxCnt = 0;
		int result = 0;
		boolean isdupl = false;
		for (int i = 0; i < 8004; i++) {
			if (cnt[i] == 0)
				continue;

			if (maxCnt < cnt[i]) {
				maxCnt = cnt[i];
				result = i - 4001;
				isdupl = false;
			} else if (maxCnt == cnt[i]) {
				isdupl = true;
			}
		}
		if (isdupl) {
			for (int i = 0; i < 8004; i++) {
				if (cnt[i] == 0)
					continue;
				if (maxCnt == cnt[i]) {
					if (isdupl) {
						isdupl = false;
						continue;
					}
					maxCnt = cnt[i];
					result = i - 4001;
					break;
				}
			}
		}

		sb.append(Math.round(sum / (float) n)).append("\n");
		sb.append(arr[n / 2]).append("\n");
		sb.append(result).append("\n");
		sb.append(arr[n - 1] - arr[0]).append("\n");

		System.out.println(sb.toString());
	}
}
