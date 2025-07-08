package List3.ex2;

public class Toalete {
    private int size;
    private int males;
    private int womans;

    public Toalete(int size) {
        this.size = size;
        males = 0;
        womans = 0;
    }

    public synchronized void mulherQuerEntrar(String name) {
        while(males > 0 || womans == size) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
        womans++;
        System.out.println("MULHER " + name + " ENTROU!");
    }

    public synchronized void homemQuerEntrar(String name) {
        while(womans > 0 || males == size) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
        males++;
        System.out.println("HOMEM " + name + " ENTROU!");
    }

    public synchronized void mulherSaiToalete(String name) {
        System.out.println("MULHER " + name + " SAIU!");
        womans--;
        notifyAll();
    }

    public synchronized void homemSaiToalete(String name) {
        System.out.println("HOMEM " + name + " SAIU!");
        males--;
        notifyAll();
    }
}