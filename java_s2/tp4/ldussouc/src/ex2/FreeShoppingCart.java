package ex2;

import java.util.ArrayList;

public class FreeShoppingCart {
	
	private ArrayList<Book> books;
	
	public FreeShoppingCart() {
		
		this.books = new ArrayList<Book>();
	}

	public ArrayList<Book> getBooks() {
		
		return books;
	}
	
	public void add(Book b){
	
		this.books.add(b);
	}
	
	public int numberOfBooks(){
		int size = this.books.size();
		return size;
	}
	
	
	public static void main(String[] args) {
		
		FreeShoppingCart newArray = new FreeShoppingCart();
		
		Book b1 = new Book("Da Java Codeee", "Duke Brown");
		//Book b2 = new Book("Da Java Code", "Duke Brown");
		//Book b3 = new Book("Da Java Code", "Duke Brown");
		// Book b4 = new Book("Da Java Code", "Duke Brown");
		
		newArray.add(b1);
		
	}


}
