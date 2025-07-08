package List3.ex2;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> womans = List.of("Annie", "Maria", "Joana", "Camila", "Carol", "Karolina", "Gabriela", "Constantina");
        List<String> males = List.of("João", "Gabriel", "Carlos", "Bruno", "Fernando", "Miguel", "Pedro", "Peter");
        Toalete toalete = new Toalete(2);

        if(womans.size() == males.size()) {
            int size = womans.size();
            for(int i = 0; i < size; i++) {
                Thread woman = new Thread(new WomanThread(toalete, womans.get(i)));
                Thread male = new Thread(new MaleThread(toalete, males.get(i)));
                woman.start();
                male.start();
            }
        }
    }
}