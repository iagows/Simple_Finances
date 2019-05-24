package com.iaspp.simple_finances;

import android.content.ContentValues;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

import java.util.Date;

public class DbModel {
    private SQLiteDatabase db;
    private DbCreation dataBaseC;

    public  DbModel(Context c){
        dataBaseC = new DbCreation(c);
    }

    public String insertData(String desc, Date date, double amount){
        ContentValues values;
        long result;

        db = dataBaseC.getWritableDatabase();
        values = new ContentValues();
        values.put(DbCreation.DESCRITION, desc);
        values.put(DbCreation.DATE, Util.dateToString(date));
        values.put(DbCreation.AMOUNT, amount);

        result = db.insert(DbCreation.TABLE, null, values);
        db.close();

        if(result==-1){
            return App.getAppResources().getString(R.string.db_error_insert);
        } else {
            return App.getAppResources().getString(R.string.db_ok_insert);
        }
    }
}
