import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static boolean[] arr;

	static void func() {
		for (int i = 2; i <= 2000; i++) {
			if (i > n)
				break;
			for (int j = i * i; j <= n; j += i) {
				arr[j] = true;
			}

		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(st.nextToken());

		arr = new boolean[n + 1];

		arr[1] = true;

		func();

		List<Integer> list = new ArrayList<>();
		for (int i = 2; i <= n; i++) {
			if (!arr[i])
				list.add(i);
		}
		int result = 0;
		int fir = 0;
		int ed = 0;

		int sum = 0;
		while (fir <= ed) {
			if (sum < n) {
				if (ed == list.size())
					break;
				sum += list.get(ed++);
			} else if (sum > n) {
				sum -= list.get(fir++);
			} else {
				sum -= list.get(fir++);
				result++;
			}
		}

		System.out.println(result);
	}

}