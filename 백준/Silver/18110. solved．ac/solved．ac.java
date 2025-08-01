import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());

		int avg = Math.round((n * 15) / 100.0f);

		int[] arr = new int[n];
		int result = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);

		int sum = 0;
		for (int i = avg; i < n - avg; i++) {
			sum += arr[i];
		}
		result = Math.round(sum / (n - (avg * 2f)));
		System.out.println(result);
	}
}
