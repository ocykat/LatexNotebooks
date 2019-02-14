import java.util.Scanner;

public class Launcher {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Input 1 for PayPal, 2 for MoneyBooker: ");
		String temp = scanner.nextLine(); 
		String payment = "";
		MoneyTransfer moneytransfer = null;
		if (temp.equals("1")) {
			System.out.print("Input balance: ");
			temp = scanner.nextLine();
			Scanner tempSc = new Scanner(temp);
			double balance = tempSc.nextInt();
			tempSc.close();
			moneytransfer = new PayPal_Adapter(balance);
			System.out.print("Input payment: ");
			payment = scanner.nextLine();
		} else if (temp.equals("2")) {
			System.out.print("Input balance: ");
			temp = scanner.nextLine();
			Scanner tempSc = new Scanner(temp);
			int balance = tempSc.nextInt();
			tempSc.close();
			moneytransfer = new MoneyBooker_Adapter(balance);
			System.out.print("Input payment: ");
			payment = scanner.nextLine();
		}
		scanner.close();
		moneytransfer.pay(payment);
	}

}
