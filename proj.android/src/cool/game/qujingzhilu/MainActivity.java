package cool.game.qujingzhilu;

import android.os.Bundle;
import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.util.Log;
import android.view.Menu;

import org.cocos2dx.lib.Cocos2dxActivity;

public class MainActivity extends Cocos2dxActivity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// Check if the system supports OpenGL ES 2.0.
		final ActivityManager activityManager = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
		final ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();
		final boolean supportsEs2 = configurationInfo.reqGlEsVersion >= 0x20000;	
		if(supportsEs2)
			Log.v("supportsEs2", "This device supports OpenGL ES 2.0");
		else
			Log.v("supportsEs2", "This device doesn't support OpenGL ES 2.0");

		  
		//setContentView(R.layout.activity_main);
	}

	static {
        System.loadLibrary("game");
    }

}
