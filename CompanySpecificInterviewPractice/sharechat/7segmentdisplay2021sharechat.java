package com.example.practice_dsalgo;

import javafx.scene.paint.Paint;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public class SharechatPractice {


    static int getminToggeel(int len, String s)
    {
        HashMap<Character, int[]> h1 = new HashMap< >();

        h1.put('0', new int[]{1, 1, 1, 1, 1, 1, 0});
        h1.put('1', new int[]{0, 1, 1, 0, 0, 0, 0});
        h1.put('2', new int[]{1, 1, 0, 1, 1, 0, 1});
        h1.put('3', new int[]{1, 1, 1, 1, 0, 0, 1});
        h1.put('4', new int[]{0, 1, 1, 0, 0, 1, 1});
        h1.put('5', new int[]{1, 0, 1, 1, 0, 1, 1});
        h1.put('6', new int[]{0, 0, 1, 1, 1, 1, 1});
        h1.put('7', new int[]{1, 1, 1, 0, 0, 0, 0});
        h1.put('8', new int[]{1, 1, 1, 1, 1, 1, 1});
        h1.put('9', new int[]{1, 1, 1, 0, 0, 1, 1});

        int [] display = new int[]{0,0,0,0,0,0,0};
        int res =0;
        for(int i=0;i< s.length(); ++i)
        {
            var arr = h1.get(s.charAt(i));
            int cnt =0;
            for(int j =0 ;j<7 ; ++j)
            {
                if(arr[j] != display[j] )
                {
                    arr[j] ^=1; ++cnt;
                }
            }
            res +=cnt;
        }
        return res;
    }



    public static void main(String[] args) {

        System.out.println(getminToggeel(2,"112452"));
    }

}
