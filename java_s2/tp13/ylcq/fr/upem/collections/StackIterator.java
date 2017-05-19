package fr.upem.collections;
import java.util.Iterator;
import java.util.Objects;
import java.util.ConcurrentModificationException;

class StackIterator<E> implements Iterator<E> {
    
    private Stack<E> stack;
    private int i, initialCount;

    public StackIterator(Stack<E> s) {
        stack = Objects.requireNonNull(s);
        initialCount = i = stack.size();
    }

    public boolean hasNext() {
        return i > 0;
    }

    public E next() {
        if(stack.size() != initialCount)
            throw new ConcurrentModificationException();
        return stack.get(--i).get();
    }
}
