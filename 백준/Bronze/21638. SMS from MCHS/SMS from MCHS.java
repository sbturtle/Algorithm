import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		int v = sc.nextInt();
		int t1 = sc.nextInt();
		int v1 = sc.nextInt();

		String result = "";
		if (t1 < 0 && v1 >= 10)
			result = "A storm warning for tomorrow! Be careful and stay home if possible!\n";

		else if (t > t1)
			result = "MCHS warns! Low temperature is expected tomorrow.\n";
		else if (v < v1)
			result = "MCHS warns! Strong wind is expected tomorrow.\n";
		else if (result.equals(""))
			result = "No message";
		System.out.println(result);

	}
}
