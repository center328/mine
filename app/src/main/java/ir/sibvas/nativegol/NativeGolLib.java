package ir.sibvas.nativegol;

/**
 * Created by m.arezoomandi on 1/30/2016.
 */
public class NativeGolLib {
    static {
        System.loadLibrary("lib4gol");
    }

    public native String encryptDecrypt(String ticket);
//    public native String decrypt(String encryptedTicket);
}
