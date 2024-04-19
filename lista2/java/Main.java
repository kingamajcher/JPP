public class Main {
    public static void main(String[] args) {
        GF a = new GF(70);
        GF b = new GF(1234588);
        GF c = new GF(-30);
        GF result;

        System.out.println("characteristic: " + a.characteristic());

        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("c = " + c);

        System.out.println("b inversed = " + b.inverse());

        result = GF.add(a, b);
        System.out.println("a + b = " + result);

        result = GF.subtract(a, b);
        System.out.println("a - b = " + result);

        result = GF.multiply(a, b);
        System.out.println("a * b = " + result);

        result = GF.divide(a, b);
        System.out.println("a / b = " + result);

        System.out.println("Is a == b? " + (a.equals(b)));
        System.out.println("Is a != b? " + (a.notEquals(b)));
        System.out.println("Is a < b? " + (a.lessThan(b)));
        System.out.println("Is a > b? " + (a.greaterThan(b)));
    }
}
