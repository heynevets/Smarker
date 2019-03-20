package com.tingyuyeh.smarkerandroid;

import android.animation.Animator;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;

public class ControlPanel extends AppCompatActivity {


    com.airbnb.lottie.LottieAnimationView animation_view;
    Button buttonUp;
    Button buttonDown;
    String DEBUG = "MAIN";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_panel);
        buttonUp = findViewById(R.id.button_up);
        buttonUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(DEBUG, "button is up");
                new ControlPanel.RetrieveFeedTask().execute("http://192.168.4.1/up");

            }
        });

        buttonDown = findViewById(R.id.button_down);
        buttonDown.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(DEBUG, "button is donw");
                new ControlPanel.RetrieveFeedTask().execute("http://192.168.4.1/down");
            }
        });

//        animation_view = findViewById(R.id.animation_view);
//        animation_view.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                animation_view.playAnimation();
//            }
//        });
//
//
//        animation_view.addAnimatorListener(new Animator.AnimatorListener() {
//            @Override
//            public void onAnimationStart(Animator animation) {
//                Log.e("Animation:","start");
//            }
//
//            @Override
//            public void onAnimationEnd(Animator animation) {
//                Log.e("Animation:","end");
//                animation_view.setProgress(0);
//            }
//
//            @Override
//            public void onAnimationCancel(Animator animation) {
//                Log.e("Animation:","cancel");
//            }
//
//            @Override
//            public void onAnimationRepeat(Animator animation) {
//                Log.e("Animation:","repeat");
//            }
//        });
    }

    class RetrieveFeedTask extends AsyncTask<String, Void, HttpResponse> {

        private Exception exception;

        protected HttpResponse doInBackground(String... urls) {
            try {
                HttpResponse response = null;
                try {
                    HttpClient client = new DefaultHttpClient();
                    HttpGet request = new HttpGet();
                    Log.d(DEBUG, urls[0]);
                    request.setURI(new URI(urls[0]));
                    response = client.execute(request);
                } catch (URISyntaxException e) {
                    e.printStackTrace();
                } catch (ClientProtocolException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                return response;
            } catch (Exception e) {
                this.exception = e;
            } finally {
            }
            return null;
        }

        protected void onPostExecute(HttpResponse response) {
        }
    }
}
