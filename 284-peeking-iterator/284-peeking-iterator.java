// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
import java.util.NoSuchElementException;

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> itr;
    private Integer next = null;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    if(iterator.hasNext())  next = iterator.next();
        itr = iterator;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return next;
	}
	
    private void moveNext(){
        next = null;
        if(itr.hasNext())   next = itr.next();
    }
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if(next == null){
            throw new NoSuchElementException();
        }
        Integer result = next;
        moveNext();
        return result;
	}
	
	@Override
	public boolean hasNext() {
	    return next != null;
	}
}