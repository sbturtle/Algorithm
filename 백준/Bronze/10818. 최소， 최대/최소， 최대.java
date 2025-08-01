import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		while(t-- != 0) {
			int num = Integer.parseInt(st.nextToken());
			if(max < num)
				max = num;
			if(min > num)
				min = num;
		}
		sb.append(min).append(" ").append(max);
		System.out.println(sb.toString());
	}

}
