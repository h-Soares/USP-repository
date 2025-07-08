package List3.ex4;

import java.math.BigDecimal;

public class CreditCard {
    private BigDecimal limit;

    public CreditCard(BigDecimal limit) {
        this.limit = limit;
    }

    public synchronized boolean withdraw(BigDecimal amount) {
        if (amount == null || amount.signum() <= 0)
            throw new IllegalArgumentException("Amount must be positive");
        
        if(limit.subtract(amount).compareTo(BigDecimal.ZERO) < 0)
            return false;
        limit = limit.subtract(amount);
        return true;
    }

    public synchronized BigDecimal getLimit() {
        return limit;
    }
}
