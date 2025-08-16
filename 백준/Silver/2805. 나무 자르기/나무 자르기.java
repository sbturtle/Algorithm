import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		long result = 0;
		int[] arr = new int[n];

		int mx = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			mx = mx < arr[i] ? arr[i] : mx;
		}

		long bg = 0, ed = mx;
		while (bg <= ed) {
			long md = (ed + bg) / 2;
			long sum = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] <= md)
					continue;
				sum += arr[i] - md;
			}

			if (sum < m) {
				ed = md - 1;
			} else {
				bg = md + 1;
				if (result < md)
					result = md;
			}
		}

		System.out.println(result);
	}
}
