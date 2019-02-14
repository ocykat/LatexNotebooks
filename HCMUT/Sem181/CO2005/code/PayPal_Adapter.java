public class PayPal_Adapter implements MoneyTransfer {
	private PayPal paypal;
	
	PayPal_Adapter(double balance) {
		paypal = new PayPal(balance);
	}
	
	public void pay(String input) {
		double amount = Double.parseDouble(input);
		paypal.sendPayment(amount);
	}
}
