package com.iaspp.simple_finances;

import android.content.Context;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Util {

    public static String dateToString(Date date){
        String format = App.getAppResources().getString(R.string.date_format);
        SimpleDateFormat sdf = new SimpleDateFormat(format);
        return sdf.format(date);
    }

    public static Date stringToDate(String date) throws ParseException {
        String format = App.getAppResources().getString(R.string.date_format);
        SimpleDateFormat sdf = new SimpleDateFormat(format);

        return sdf.parse(date);
    }
}
