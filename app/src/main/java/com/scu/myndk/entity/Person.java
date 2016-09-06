package com.scu.myndk.entity;

/**
 * Created by zhangqianchu on 2016/8/5.
 */
public class Person {
    String name;
   public int age;
    boolean gender;
    public Person(){
        scores = new int[100];
        for (int i=0;i<scores.length;i++){
            scores[i] = i;
        }
    }
    public  int scores[];

    static {
        System.loadLibrary("MyLibrary");
    }

    public native int average(Person person[],int len);
    public native int averages(int[] scores,int len);
}
