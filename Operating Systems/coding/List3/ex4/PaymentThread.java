package List3.ex4;

import java.math.BigDecimal;
import java.util.concurrent.ThreadLocalRandom;

public class PaymentThread implements Runnable {
    private CreditCard creditCard;
    private BigDecimal amountToWithdraw;

    public PaymentThread(CreditCard creditCard, BigDecimal amountToWithdraw) {
        this.creditCard = creditCard;
        this.amountToWithdraw = amountToWithdraw;
    }

    @Override
    public void run() {
        long seconds = ThreadLocalRandom.current().nextLong(1, 4) * 1000;
        try {
            Thread.sleep(seconds);
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        if(creditCard.withdraw(amountToWithdraw))
            System.out.println("Amount withdrawn: " + amountToWithdraw);
        else
            System.out.println("Can not withdraw amount " + amountToWithdraw);
    }
}