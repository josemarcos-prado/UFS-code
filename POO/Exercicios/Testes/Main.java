class B extends D{ }
abstract class D { }
class A extends B { }
abstract class  C extends D { }
class E extends C { }
public class Main {
    public static void main (String args []) {
        A a;
        B b;
        C c;
        D d;
        E e;
        b = new B();
        a = new A();
        d = a;
        c = new E();
        d = c;
        // c = new C();
        // d = new D();
        // a = (A) b;
    }
}