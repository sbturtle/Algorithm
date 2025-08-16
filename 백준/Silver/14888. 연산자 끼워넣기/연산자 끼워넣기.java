import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = { 1, -1 };
	static int n;
	static int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
	static int[] arr;
	static int[] oper;

	static void func(int sum, int idx) {

		if (idx == n) {
			if (mx < sum)
				mx = sum;
			if (mn > sum)
				mn = sum;
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (oper[i] == 0)
				continue;

			int s = sum;
			if (i == 2) {
				s *= arr[idx];
			} else if (i == 3) {
				s /= arr[idx];
			} else {
				s += arr[idx] * dx[i];
			}
			oper[i]--;
			func(s, idx + 1);
			oper[i]++;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());

		arr = new int[n];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		oper = new int[4]; // +, -, *, /
		for (int i = 0; i < 4; i++) {
			oper[i] = Integer.parseInt(st.nextToken());
		}

		func(arr[0], 1);

		System.out.printf("%d\n%d", mx, mn);
	}
}
