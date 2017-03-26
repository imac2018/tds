class A { 
	protected int x() {
		return 3;
	}
	public void printX() {
		System.out.println(x());
	}
}
class B extends A {
	public int x() {
		return 4;
	}
}
class Test {
    // 1.
    // C'est parti
	public static void main(String[] args) {
		A a = new A();
		System.out.println(a.x()); // C'est x() de A => 3
		a.printX(); // C'est printX() qui affiche x() de A => 3

		B b = new B();
		System.out.println(b.x()); // C'est x() de B => 4
		b.printX(); // C'est printX() qui affiche x() de B => 4

		A ab = new B();
		System.out.println(ab.x());
        // ^ On instancie un B, donc c'est sa vtable qui est chargée.
        // Ca affiche 4.
		ab.printX(); // Idem... C'est printX() de A, qui affiche le x() de B.
	}
}
// 2.
// B a accès à deux méthodes x() : x() et super.x().
// 3.
