package com.scu.myndk.socket;

import com.scu.myndk.MainActivity;

/**
 * Created by zhangqianchu on 2016/8/3.
 */
public class DataHolder {
    public DataHolder(){

    }
    public void putData(String json) {    //Native 回调,显示数据给TextView
        MainActivity.act.updateStatus(json);
    }
}
