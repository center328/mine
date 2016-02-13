package ir.sibvas.nativegol;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView text1 = (TextView) findViewById(R.id.text1);
        TextView text2 = (TextView) findViewById(R.id.text2);
        NativeGolLib nativeGolLib = new NativeGolLib();
        String str = nativeGolLib.encryptDecrypt("i am mahdi arezoumandi.");
        text1.setText(str);
        text2.setText(nativeGolLib.encryptDecrypt(str));
    }
}
