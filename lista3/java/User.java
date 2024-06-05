// User.java

import java.util.Random;

public class User {

    private DHSetup dhSetup;
    
    private GF key;
    
    private long secret = -1;

    public User(DHSetup dhSetup) {
        this.dhSetup = dhSetup;
        Random random = new Random();
        secret = random.nextInt(GF.characteristic()) + 1;
    }

    public GF getPublicKey() {
        return dhSetup.power(dhSetup.getGenerator(), secret);
    }

    public void setKey(GF a) {
        if (secret == -1) {
            throw new IllegalStateException("Secret not initialized");
        }
        this.key = dhSetup.power(a, secret);
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
