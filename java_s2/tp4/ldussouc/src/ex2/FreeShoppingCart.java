package ex2;

import java.util.LinkedList;
import java.util.Iterator;

public class FreeShoppingCart {
	
	private LinkedList<Book> books;
	
	public FreeShoppingCart() {
		
		this.books = new LinkedList<Book>();
	}

	public LinkedList<Book> getBooks() {
		
		return books;
	}
	
	public void add(Book b){
	
		this.books.add(b);
	}
	
	public int numberOfBooks(){
		int size = this.books.size();
		return size;
	}
	
	// longest title using count + ArrayList.get()
	/*public void longestTitle(){
		
		int longestTitle = 0;
		String titleToReturn = null;
		
		System.out.println("Le livre avec le titre le plus long : ");
		
		for(int i = 0; i < this.books.size(); ++i){
			if(this.books.get(i).getTitle().length() > longestTitle){
				longestTitle = this.books.get(i).getTitle().length();
				titleToReturn = this.books.get(i).getTitle();
			}
		}
		
		System.out.println(titleToReturn);
	}*/
	
	// longest title using Iterator
	/*public void longestTitle(){
		
		System.out.println("Le livre avec le titre le plus long : ");
		
		Iterator<Book> bi = this.books.iterator();
		
		
        while(bi.hasNext()){
    	  
    	    if( bi.next().getTitle().length() > longestTitle.getTitle().length() )
    	    	longestTitle = bi.next();
	    }
        
        System.out.println(longestTitle.getTitle());
	}*/
	
	public void longestTitle(){
		
		Book longestTitle = this.books.get(0);
		
		for(Iterator<Book> bi = this.books.iterator(); bi.hasNext(); )
			if( bi.next().getTitle().length() > longestTitle.getTitle().length() )
    	    	longestTitle = bi.next();
		
		System.out.println(longestTitle.getTitle());
	}
	
	
	/*public void removeFirstOccurence(Book b){
		
		this.books.remove(b);
	}*/
	
	public void removeFirstOccurence(Book b){
		
		for(Iterator<Book> bi = books.iterator() ; bi.hasNext(); )
            if(b.equals(bi.next())) 
                bi.remove();
	}
	
	public static void main(String[] args) {
		
		FreeShoppingCart newArray = new FreeShoppingCart();
		
		Book b1 = new Book("Da Java Codeee", "Duke Brown");
		Book b2 = new Book("Da Java Code", "Duke Brown");
		//Book b3 = new Book("Da Java Code", "Duke Brown");
		// Book b4 = new Book("Da Java Code", "Duke Brown");
		
		newArray.add(b1);
		newArray.add(b2);
		
		System.out.println(newArray.numberOfBooks());
		newArray.longestTitle();
		newArray.removeFirstOccurence(b2);
		
		System.out.println(newArray.numberOfBooks());
	}
}
