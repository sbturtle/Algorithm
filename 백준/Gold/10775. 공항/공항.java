import java.util.*;
import java.io.*;

public class Main {

	static int g, ps, result = 0;

	static int[] gate;
	static boolean[] isvis;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		g = Integer.parseInt(br.readLine());
		ps = Integer.parseInt(br.readLine());
		gate = new int[g + 1];
		isvis = new boolean[g + 1];
		for (int i = 1; i <= g; i++) {
			gate[i] = i - 1;
		}

		while (ps-- != 0) {
			int p = Integer.parseInt(br.readLine());
			int idx = p;
			while (idx > 0 && isvis[idx]) {
				idx = gate[idx];
			}
			if (idx == 0)
				break;

			result++;
			gate[p] = idx - 1;
			isvis[idx] = true;
		}

		System.out.println(result);
	}
}
