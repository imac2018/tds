package fr.upem.collections;
import java.util.Optional;
import java.util.Objects;
import java.util.Iterator;
import java.util.ArrayList;

public class Stack<E> implements Iterable<E> {

    private E[] internalArray;
    private int internalCount;

    public Stack(int maxElementCount) {
        if(maxElementCount <= 0) {
            throw new IllegalArgumentException("maxElementCount must be greater than 0 !");
        }
        // osef du warning, sérieux
        internalArray = (E[]) new Object[maxElementCount];
        internalCount = 0;
    }

    public int size() {
        return internalCount;
    }

    public void push(E elem) {
        if(internalCount >= internalArray.length)
            throw new IllegalStateException("Running out of space!");
        internalArray[internalCount++] = Objects.requireNonNull(elem);
    }

    public Optional<E> pop() {
        if(internalCount <= 0)
            return Optional.empty();
        return Optional.of(internalArray[--internalCount]);
    }

    public Iterator<E> iterator() {
        return new StackIterator<E>(this);
    }

    // For StackIterator
    public Optional<E> get(int i) {
        if(i<0 || i>=internalCount)
            return Optional.empty();
        return Optional.of(internalArray[i]);
    }
}
