import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int[] arr;

	static int lower(int f) {
		int st = 0;
		int ed = n - 1;
		while (st <= ed) {
			int md = (st + ed) / 2;

			if (arr[md] < f) {
				st = md + 1;
			} else {
				ed = md - 1;
			}
		}

		return st;
	}

	static int upper(int f) {
		int st = 0;
		int ed = n - 1;
		while (st <= ed) {
			int md = (st + ed) / 2;

			if (arr[md] <= f) {
				st = md + 1;
			} else {
				ed = md - 1;
			}
		}

		return st;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(st.nextToken());

		arr = new int[n];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		while (m-- != 0) {
			int f = Integer.parseInt(st.nextToken());
			int low = lower(f);
			int up = upper(f);
			int cnt = up - low;
			sb.append(cnt).append(" ");
		}

		System.out.println(sb);
	}
}
