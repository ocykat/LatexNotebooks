public class MoneyBooker_Adapter implements MoneyTransfer {
	private MoneyBooker moneybooker;
	
	MoneyBooker_Adapter(int amount) {
		moneybooker = new MoneyBooker(amount);
	}
	
	public void pay(String input) {
		int amount = Integer.parseInt(input);
		moneybooker.payMoney(amount);
	}
}
