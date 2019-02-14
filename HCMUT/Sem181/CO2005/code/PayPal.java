public class PayPal {
	private double balance;
	
	public PayPal(double balance) {
		this.balance = balance;
	}
	
	public void sendPayment(double amount) {
		if (balance >= amount) {
			balance -= amount;
			System.out.println(amount + " sent.");
		} else {
			System.out.println("Not enough balance.");
		}
	}
	
	public double getBalance() {
		return balance;
	}
}
