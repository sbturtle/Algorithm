import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		char[] str1 = st.nextToken().toCharArray();
		st = new StringTokenizer(br.readLine());
		char[] str2 = st.nextToken().toCharArray();

		int[] cnt1 = new int['z' - 'a' + 1];
		for (int i = 0; i < str1.length; i++) {
			cnt1[str1[i] - 'a']++;
		}
		int[] cnt2 = new int['z' - 'a' + 1];
		for (int i = 0; i < str2.length; i++) {
			cnt2[str2[i] - 'a']++;
		}
		
		int result = 0;
		for (int i = 0; i < cnt1.length; i++) {
			result += Math.abs(cnt1[i] - cnt2[i]);
		}

		System.out.println(result);
	}
}
