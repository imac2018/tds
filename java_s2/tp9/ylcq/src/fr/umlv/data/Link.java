package fr.umlv.data;
import java.util.Optional;
import java.util.Objects;

class Link<E> {
    final E value;
    Optional<Link<E>> next;

    public Link(E value) {
        this.value = value;
        this.next = Optional.empty();
    }
    public Link(E value, Link<E> prev) {
        this(value);
        Objects.requireNonNull(prev);
        prev.next = Optional.of(this);
    }


    /*
    public static void main(String[] args) {
        new Link(13, Optional.of(new Link(144)));
    }
    */
}

// 2.
// C'est java fr.umlv.data.Link.
