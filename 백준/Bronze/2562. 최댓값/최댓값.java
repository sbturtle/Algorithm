import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int max = 0, idx = 0;

		for (int i = 0; i < 9; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());

			if (max < n) {
				max = n;
				idx = i;
			}
		}

		sb.append(max).append("\n").append(idx + 1);
		System.out.println(sb.toString());
	}

}
