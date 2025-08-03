import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(st.nextToken());

		check: while (T-- != 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());

			Set<String> set = new HashSet<>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				set.add(st.nextToken());
			}

			for (String str : set) {
				char[] arr = str.toCharArray();
				StringBuilder s = new StringBuilder();

				for (int i = 0; i < arr.length - 1; i++) {
					s.append(arr[i]);
					if (set.contains(s.toString())) {
						sb.append("NO").append("\n");
						continue check;
					}
				}
			}
			sb.append("YES").append("\n");
		}

		System.out.println(sb.toString());
	}
}
