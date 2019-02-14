public class MoneyBooker {
	private int Amount;
	
	MoneyBooker(int Amount) {
		this.Amount = Amount;
	}
	
	public void payMoney(int Amount) {
		if (this.Amount >= Amount) {
			this.Amount -= Amount;
			System.out.println(Amount + " sent.");
		} else {
			System.out.println("Not enough money.");
		}
	}
}
