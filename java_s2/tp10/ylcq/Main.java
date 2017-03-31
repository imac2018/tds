import java.util.*;
import java.util.stream.*;
import java.util.function.*;

public class Main {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("hello", "world", "hello", "lambda");
        System.out.println(count(list, "hello"));
        System.out.println(count2(list, "hello"));
        System.out.println(count3(list, "hello"));
        System.out.println(upperCase(list));
        System.out.println(upperCase2(list));
        System.out.println(upperCase3(list));
        System.out.println(upperCase4(list));
        ex4();
        bench();
    }
    // Ex1.1.
    static long count(List<String> list, String searched) {
        long cnt = 0;
        for(String s : list)
            if(s.equals(searched))
                ++cnt;
        return cnt;
    }
    // Ex1.2.
    static long count2(List<String> list, String searched) {
        return list.stream().filter(s -> s.equals(searched)).count();
    }
    // Ex2.1.
    static List<String> upperCase(List<String> list) {
        List<String> out = new ArrayList<String>();
        for(String s : list)
            out.add(s.toUpperCase());
        return out;
    }
    // Ex2.2.
    static List<String> upperCase2(List<String> list) {
        List<String> out = new ArrayList<String>();
        list.stream().map(s -> s.toUpperCase()).forEach(s -> out.add(s));
        return out;
    }
    // Ex2.3.
    static List<String> upperCase3(List<String> list) {
        List<String> out = new ArrayList<String>();
        list.stream().map(String::toUpperCase).forEach(s -> out.add(s));
        return out;
    }
    // Ex2.4.
    static List<String> upperCase4(List<String> list) {
        return list.stream().map(String::toUpperCase).collect(Collectors.toList());
    }
    // Ex3.1.
    // On appelle mapToInt() car on sait que l'on est limité à renvoyer un int.
    // mapToInt() va nous renvoyer un IntStream sur lequel on va pouvoir sommer.
    //
    // Ex3.2.
    static int count3(List<String> list, String searched) {
        return list.stream().mapToInt(s -> s.equals(searched) ? 1 : 0).sum();
    }
    // Ex4.1
    // list2 contient une liste de 1 million de chaînes de caractères représentant
    // chacune un nombre tiré au hasard entre 0 (inclusif) et 100 (exclusif).
    static void ex4() {
        List<String> list2 = new Random(0)
            .ints(1_000_000, 0, 100)
            .mapToObj(Integer::toString)
            .collect(Collectors.toList());
        printAndTime(() -> count(list2, "33"));
        printAndTime(() -> count2(list2, "33"));
        printAndTime(() -> count3(list2, "33"));
    }
    // Ex4.2
    // Ex4.3
    static void printAndTime(LongSupplier fn) {
        long start = System.nanoTime();
        long result = fn.getAsLong();
        long end = System.nanoTime();
        System.out.println("result " + result);
        System.out.println("elapsed time " + (end - start));
    }
    // Ex4.4
    // A première vue, on pourrait croire que la performance diffère entre les 
    // trois méthodes, mais :
    // - En relançant plusieurs fois de suite le programme, on observe que les moyennes
    //   des temps écoulés s'égalisent.
    // - Le benchmark ne prend pas assez de temps pour être signifiant.
    //
    // Ci-dessous j'ai juste multiplié par 10 le nombre d'éléments de la liste, mais on
    // voit clairement dans le benchmark que le temps écoulé est de plus en plus bas à 
    // travers les méthodes count*(). On peut supposer que c'est le JIT.
    static void bench() {
        List<String> list2 = new Random(0)
            .ints(10_000_000, 0, 100)
            .mapToObj(Integer::toString)
            .collect(Collectors.toList());
        printAndTime(() -> count(list2, "33"));
        printAndTime(() -> count2(list2, "33"));
        printAndTime(() -> count3(list2, "33"));
    }
}
