package com.example.taxifinder.model

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity
data class TaxiCompany (
    @PrimaryKey(autoGenerate = true)
    var id: Int = 0,
    @ColumnInfo(name = "name") var name: String = "Default TaxiCompany name",
    @ColumnInfo(name = "address") var address: String = "Default TaxiCompany address",
    @ColumnInfo(name = "phoneNumber") var phoneNumber: String = "Default TaxiCompany phone number"
)