package com.iaspp.simple_finances;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DbCreation extends SQLiteOpenHelper {
    private static final String DB_NAME = "meow_finances.db";
    public static final String TABLE = "income_outcome";
    public static final String ID = "_id";
    public static final String DESCRITION = "description";
    public static final String DATE = "date";
    public static final String AMOUNT = "amount";
    private static final int VERSAO = 1;

    public DbCreation(Context context) {
        super(context, DB_NAME, null, VERSAO);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "CREATE TABLE " + TABLE + " (" +
                ID + " INTEGER NOT NULL UNIQUE," +
                DESCRITION + " TEXT NOT NULL," +
                DATE + " TEXT NOT NULL," +
                AMOUNT + " REAL NOT NULL," +
                "PRIMARY KEY(" + ID + ")" +
                ");";
        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        //MODIFICAÇÕES NECESSÁRIAS NA TABELA DA VERSÃO 1.0
    }
}
