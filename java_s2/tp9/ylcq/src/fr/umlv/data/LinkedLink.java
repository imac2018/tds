package fr.umlv.data;
import java.util.Optional;
import java.util.Objects;
import fr.umlv.data.Link;

// Ex3.1
// L'intérêt d'utiliser un type paramétré XXX

public class LinkedLink<E> {
    private final Link<E> root;
    private Link<E> tail;
    public LinkedLink(E value) {
        tail = root = new Link<E>(value);
    }
    public LinkedLink<E> add(E value) {
        tail = new Link<E>(value, tail);
        return this;
    }
    public @Override String toString() {
        StringBuilder sb = new StringBuilder();
        for(Optional<Link<E>> cur=Optional.of(root) ; cur.isPresent() ; cur = cur.get().next) {
            sb.append(cur.get().value);
            if(cur.get().next.isPresent())
                sb.append(" ");
        }
        return sb.toString();
    }
    public Optional<E> get(int index) {
        int i = 0;
        for(Optional<Link<E>> cur=Optional.of(root) ; cur.isPresent() ; cur = cur.get().next) {
            if(i == index)
                return Optional.of(cur.get().value);
            ++i;
        }
        return Optional.empty();
    }
    // Ex3.4 Pourquoi prendre un Object ?
    // Aucune idée a priori, mais les Internets le savent !
    // http://stackoverflow.com/a/859239
    // http://stackoverflow.com/a/2994356
    // Le résumé, c'est que rien ne force notre paramètre a être
    // du même type que les éléments de notre liste : Il y a juste
    // besoin qu'il aie le potentiel d'égalité.
    // Notre utilisateur pourrait créer une liste de Foos, et demander
    // si elle contient un certain Bar, tant qu'il peut avoir égalité
    // potentielle entre leurs deux contenus.
    public boolean contains(Object o) {
        for(Optional<Link<E>> cur=Optional.of(root) ; cur.isPresent() ; cur = cur.get().next)
            if(o.equals(cur.get()))
                return true;
        return false;      
    }
} 
