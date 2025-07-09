public class App {
    public static void main(String[] args) {
        System.out.println("Se ocorrer o mesmo valor: SINGLETON FUNCIONOU!");
        System.out.println("Se ocorrerem valores diferentes: PROBLEMA!");

        SimpleSingleton singleton = SimpleSingleton.getInstance(1930);
        SimpleSingleton anotherSingleton = SimpleSingleton.getInstance(1914);
        SimpleSingleton anotherSingleton2 = SimpleSingleton.getInstance(1910);

        System.out.println(singleton.getValue());
        System.out.println(anotherSingleton.getValue());
        System.out.println(anotherSingleton2.getValue()); 
    }
}