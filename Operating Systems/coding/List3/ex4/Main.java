package List3.ex4;

import java.math.BigDecimal;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        CreditCard creditCard = new CreditCard(BigDecimal.TEN);
        CardPayment cardPayment = new CardPayment(creditCard, List.of(BigDecimal.ONE, BigDecimal.valueOf(2), BigDecimal.valueOf(4), 
            BigDecimal.valueOf(2), BigDecimal.valueOf(1), BigDecimal.TEN));

        cardPayment.makeWithdraws();
    }
}