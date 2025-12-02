import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		char[] str = br.readLine().toCharArray();
		Stack<Character> st = new Stack<>();
		int result = 0;
		int sum = 1;

		for (int i = 0; i < str.length; i++) {
			if (str[i] == '(') {
				st.push(str[i]);
				sum *= 2;
			} else if (str[i] == '[') {
				st.push(str[i]);
				sum *= 3;
			} else if (str[i] == ')') {
				if (st.isEmpty() || st.peek() != '(') {
					result = 0;
					break;
				} else if (str[i - 1] == '(') {
					result += sum;
				}
				st.pop();
				sum /= 2;
			} else if (str[i] == ']') {
				if (st.isEmpty() || st.peek() != '[') {
					result = 0;
					break;
				} else if (str[i - 1] == '[') {
					result += sum;
				}
				st.pop();
				sum /= 3;
			}
		}
		if (!st.isEmpty())
			sb.append(0).append("\n");
		else
			sb.append(result).append("\n");
		System.out.println(sb);
	}
}