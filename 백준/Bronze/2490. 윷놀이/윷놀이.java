import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			int zCnt = 0;
			int oCnt = 0;
			for (int j = 0; j < 4; j++) {
				String y = st.nextToken();
				if (y.equals("0"))
					zCnt++;
				else
					oCnt++;
			}

			if (zCnt == 1)
				sb.append("A\n");
			else if (zCnt == 2)
				sb.append("B\n");
			else if (zCnt == 3)
				sb.append("C\n");
			else if (zCnt == 4)
				sb.append("D\n");
			else
				sb.append("E\n");
		}

		System.out.println(sb.toString());
	}
}
