import fr.upem.collections.Stack;
import java.util.List;
import java.util.LinkedList;

// 6.
// Iterable<String> est une interface qu'une collection capable de donner 
// un iterator sur des String devrait implémenter.
// Iterator<String> est une interface qu'une classe capable d'itérer sur
// des String devrait implémenter.

public class Ex1 {
    public static void main (String[] args) {
        Stack<Integer> si = new Stack<>(2);
        si.push(1);
        si.push(2);
        for(Integer i : si) {
            System.out.println(i); 
        }
        Stack<String> ss = new Stack<>(2);
        ss.push("msg1");
        ss.push("msg2");
        for(String msg : ss) {
            System.out.println(msg); 
        }

        List<String> list = new LinkedList<>();
        list.add("zero");
        list.add("one");
        list.add("two");
        list.add("three");
        list.add("four");
        list.add("five");
        list.add("six");
        list.add("seven");
        list.add("eight");

        Stack<String> stack = new Stack<>(list.size()+1); 
        
        // 8. Cet argument est une lambda.
        //list.forEach(s->stack.push(s));
        // Remplacement par une method reference :
        list.forEach(stack::push);
        
        // 8. Cette boucle est une horreur car on devrait utiliser la boucle
        // "foreach" à la place: si un jour on change le type de la collection
        // utilisée, et qu'elle ne supporte pas l'indexation, on devra réécrire
        // cette boucle.
        // Sa complexité est en O(n^2) sur la taille de la liste car c'est
        // une liste chainée, et donc get() a besoin de repartir du début
        // à chaque fois !
        for(int i=0; i<list.size(); i++) {
            System.out.println(list.get(i));
        }
        // La version linéaire:
        for(String s: list) {
            System.out.println(s);
        }
        
        // Ces deux boucles se comportent différamment car l'ordre d'itération
        // n'est pas le m^eme : souvenons-nous que notre Stack itère dans
        // l'ordre des pop().
        // Bon ok, après y'a l'histoire du fail-fast. C'est corrigé maintenant,
        // et on peut les commenter toutes les deux car elles ne sont pas
        // censées marcher.
        // Ca ne peut jamais arriver en Rust, mais bon, personne n'est parfait !
        /*
        for(String msg : stack) {
            if(msg.equals("two")) {
                stack.push("two");
            }
        }
        for(String msg : list) {
            if(msg.equals("two")) {
                list.add("two");
            }
        }
        */

        // Un iterator "fail-fast" est un itérateur qui vérifie ses conditions
        // de manière agressive pour détecter un état incohérent _avant_ qu'il
        // y aie des dégats.

        System.out.println(list);
        list.sort(null);
        System.out.println(list);

        // La méthode sort() trie la liste (duh!).
        // Le critère, ici null, indique qu'il faut utiliser le comparateur
        // par défaut des éléments de la liste, suivant l'ordre naturel.
        
        list.sort((l, r) -> l.length() - r.length());
        System.out.println(list);
    }
}
