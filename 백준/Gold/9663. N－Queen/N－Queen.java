import java.util.*;
import java.io.*;

class Main {
	static int n;
	static int result;
	static boolean[] sero;
	static boolean[] lvis; // i + cnt + 1
	static boolean[] rvis; // (n - i) + cnt

	static void func(int cnt) {
		if (cnt == n) {
			result++;
			return;
		}

		for (int i = 0; i < n; i++) {
			int l = i + cnt + 1;
			int r = (n - i) + cnt;
			if (sero[i] || lvis[l] || rvis[r])
				continue;
			lvis[l] = true;
			rvis[r] = true;
			sero[i] = true;
			func(cnt + 1);
			lvis[l] = false;
			rvis[r] = false;
			sero[i] = false;
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(st.nextToken());
		sero = new boolean[n + 1];
		lvis = new boolean[n * 2];
		rvis = new boolean[n * 2];

		func(0);

		System.out.println(result);
	}
}