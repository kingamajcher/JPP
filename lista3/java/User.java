import java.util.Random;

public class User {
    private DHSetup dhSetup;
    private GF secret;
    private GF key;
    private long secretValue = -1;

    public User(DHSetup dhSetup) {
        this.dhSetup = dhSetup;
        Random random = new Random();
        secretValue = random.nextInt(GF.characteristic()) + 1;
    }

    public GF getPublicKey() {
        return dhSetup.power(dhSetup.getGenerator(), secretValue);
    }

    public void setKey(GF a) {
        if (secretValue == -1) {
            throw new IllegalStateException("Secret not initialized");
        }
        this.key = dhSetup.power(a, secretValue);
    }

    public GF encrypt(GF m) {
        if (key == null) {
            throw new IllegalStateException("Key not set");
        }
        return GF.multiply(m, key);
    }

    public GF decrypt(GF c) {
        if (key == null) {
            throw new IllegalStateException("Key not set");
        }
        return GF.divide(c, key);
    }
}
