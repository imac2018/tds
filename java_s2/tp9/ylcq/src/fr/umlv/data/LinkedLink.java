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
    public LinkedLink add(E value) {
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
    // Ex3.4 XXX Pourquoi prendre un Object ?
    public boolean contains(Object o) {
        for(Optional<Link<E>> cur=Optional.of(root) ; cur.isPresent() ; cur = cur.get().next)
            if(o == cur.get())
                return true;
        return false;      
    }
} 
