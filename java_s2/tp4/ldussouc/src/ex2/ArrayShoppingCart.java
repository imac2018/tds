package ex2;

public class ArrayShoppingCart {
	
	// Il n'est pas intéressant d'utiliser un champ statique, il est préférable d'utiliser une variable
	// qui contient la méthode length du tableau pour obtenir sa taille
	
	private Book[] books;
	private int count;
	
	public ArrayShoppingCart(int size) {
		
		this.books = new Book[size];
		this.count = 0;
	}
	
	public Book[] getBooks() {
		
		return this.books;
	}
	
	public void add(Book book) {
		
		if (this.count < this.books.length){
			
			this.books[this.count] = book;
			++this.count;
		}
		
		else{
			
			throw new ArrayIndexOutOfBoundsException("Tu pues du cul !");				
		}	
	}
	
	public int numberOfBooks(){
		
		int countBooks = this.books.length;
		
		for(int i = 0; i < this.books.length; ++i)
			if(this.books[i] == null)
				--countBooks;
		
		return countBooks;
	}
	
	public void longestTitle(){
		
		int longestTitle = 0;
		String titleToReturn = null;
		
		System.out.println("Le livre avec le titre le plus long : ");
		
		for(int i = 0; i < this.count; ++i){
			if(this.books[i].getTitle().length() > longestTitle){
				longestTitle = this.books[i].getTitle().length();
				titleToReturn = this.books[i].getTitle();
			}
		}
	
		System.out.println(titleToReturn);
	}
	
	public void getShoppingCartDetails(){
		
		System.out.println("Nombre de livres stockés : "+ numberOfBooks());
		
		for(int i = 0; i < this.count; ++i)
			System.out.println(this.books[i]);
	}

	public static void main(String[] args) {
		
		ArrayShoppingCart newArray = new ArrayShoppingCart(3);
		
		Book b1 = new Book("Da Java Codeee", "Duke Brown");
		Book b2 = new Book("Da Java Code", "Duke Brown");
		//Book b3 = new Book("Da Java Code", "Duke Brown");
		//Book b4 = new Book("Da Java Code", "Duke Brown");
		
		newArray.add(b1);
		newArray.add(b2);
		//newArray.add(b3);
		//newArray.add(b4);
		
		newArray.getShoppingCartDetails();
		newArray.longestTitle();
	}
}

