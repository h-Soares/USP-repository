package List3.ex4;

import java.math.BigDecimal;
import java.util.LinkedList;
import java.util.List;

public class CardPayment {
    private CreditCard creditCard;
    private List<BigDecimal> amountsToWithdraw;

    public CardPayment(CreditCard creditCard, List<BigDecimal> amountsToWithdraw) {
        this.creditCard = creditCard;
        this.amountsToWithdraw = amountsToWithdraw;
    }
    
    public void makeWithdraws() {
        List<Thread> threads = new LinkedList<>();

        for(BigDecimal amount : amountsToWithdraw) {
            Thread thread = new Thread(new PaymentThread(creditCard, amount));
            threads.add(thread);
            thread.start();
        }

        for(Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
        System.out.println("REMAINING LIMIT: " + creditCard.getLimit());
    }
}