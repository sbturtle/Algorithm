import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[] arr = new int[n];
		long mx = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
			if (mx < arr[i])
				mx = arr[i];
		}

		long result = 0;
		long bg = 1;
		long ed = mx;

		while (bg <= ed) {
			long md = (bg + ed) / 2;

			int cnt = 0;
			for (int i = 0; i < arr.length; i++) {
				cnt += arr[i] / md;
			}

			if (cnt < m) {
				ed = md - 1;
			} else {
				if (result < md)
					result = md;
				bg = md + 1;
			}
		}

		System.out.println(result);
	}
}