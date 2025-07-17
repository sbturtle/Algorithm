import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		StringTokenizer st = new StringTokenizer(br.readLine());
				
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		//int arr[][] = new int[n][m];
		int mn = Integer.MAX_VALUE;
		long sum = 0;
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				//arr[i][j] = 
				int num = Integer.parseInt(st.nextToken());
				sum += num;
				if(mn > num)
					mn = num;
			}			
		}
		
		System.out.println(sum - mn);
	}

}
