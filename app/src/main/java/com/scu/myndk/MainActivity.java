package com.scu.myndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.scu.myndk.entity.Native;
import com.scu.myndk.entity.Person;
import com.scu.myndk.socket.SocketJNI;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    TextView txt;
    public static MainActivity act;
    private boolean isCon;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        txt = (TextView)findViewById(R.id.text);
        txt.setOnClickListener(this);
        findViewById(R.id.button).setOnClickListener(this);
        findViewById(R.id.button1).setOnClickListener(this);
        findViewById(R.id.button2).setOnClickListener(this);
        findViewById(R.id.button3).setOnClickListener(this);
        act = this;
    }

    @Override
    public void onClick(View view) {

//        if (!isCon){
//            isCon = true;
//            txt.setText("do connect");
//            t.start();
//        }
        switch (view.getId()){
            case R.id.text:
                MyNdk ndk = new MyNdk(this);
               ndk.getChangeString("测试啦");
                break;
            case R.id.button:
                MyNdk nativ = new MyNdk(this);
                StringBuilder sb = new StringBuilder();
                nativ.changeBytes(nativ.mBytes,nativ.mBytes.length);
                for (int i=0;i< Native.TEST_BUFFER_SIZE;i++){
                    sb.append(i+"="+nativ.mBytes[i]+"\n");
                }
                txt.setText(sb.toString());
                break;
            case R.id.button1:
                MyNdk myNdk = new MyNdk(this);
                myNdk.toast(this);
                break;
            case R.id.button2:
                Person p = new Person();
                Toast.makeText(this,"平均分数是："+p.averages(p.scores,p.scores.length)+"",0).show();
                break;
            case R.id.button3:
                Person ps[] = new Person[10];
                for (int i=0;i<ps.length;i++){
                    ps[i] = new Person();
                    ps[i].age = i;
                }
                Person p1 = new Person();
                Toast.makeText(this,"平均分数是："+p1.average(ps,ps.length)+""+ps.toString(),0).show();
                break;
        }
    }


    Thread t = new Thread() {
        @Override
        public void run() {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            connect();
        }
    };

    @Override
    public void onUserInteraction() {
        //Called when the user interacts with the activity
        super.onUserInteraction();
    }

    @Override
    protected void onUserLeaveHint() {
        //only called when onUserInteraction() is called first
        super.onUserLeaveHint();
    }

    private void connect() {
        int port = 9001;
        String ip = "172.28.151.110";
        SocketJNI.doConnect(ip, port);
    }

    public void updateStatus(final String text) {
        Log.d("updateStatus", "get network data.....");
        isCon = false;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                txt.setText(text);
            }
        });
    }

}
