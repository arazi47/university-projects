package com.example.testappnavidrawer.model

import androidx.room.*

@Dao
interface TaxiCompanyDao {
    @Query("SELECT * FROM taxicompany")
    fun getAll(): List<TaxiCompany>

    @Query("SELECT * FROM taxicompany WHERE name LIKE :name")
    fun findByName(name: String): TaxiCompany

    @Insert
    fun insertAll(vararg taxiCompany: TaxiCompany)

    @Delete
    fun delete(todo: TaxiCompany)

    @Query("DELETE FROM taxicompany")
    fun deleteAll()

    @Update
    fun updateTaxiCompany(vararg taxicompanies: TaxiCompany)
}

@Database(entities = arrayOf(TaxiCompany::class), version = 1)
abstract class AppDatabase : RoomDatabase() {
    abstract fun taxiCompany(): TaxiCompanyDao
}