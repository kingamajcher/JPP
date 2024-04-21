public class Main {
    public static void main(String[] args) {
        DHSetup dhSetup = new DHSetup();

        User alice = new User(dhSetup);
        User bob = new User(dhSetup);

        System.out.println("prime: " + GF.characteristic());
        System.out.println("generator: " + dhSetup.getGenerator());

        System.out.println("Alice's public key: " + alice.getPublicKey());
        System.out.println("Bob's public key: " + bob.getPublicKey());

        alice.setKey(bob.getPublicKey());
        bob.setKey(alice.getPublicKey());

        GF message = new GF(1234); // Wiadomość do zaszyfrowania

        GF encrypted = alice.encrypt(message);
        System.out.println("Encrypted message: " + encrypted);

        GF decrypted = bob.decrypt(encrypted);
        System.out.println("Decrypted message: " + decrypted);
    }
}