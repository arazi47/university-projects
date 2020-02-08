package com.example.testappnavidrawer.model

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity
data class TaxiCompany (
    @PrimaryKey(autoGenerate = true)
    var id: Int = 0,
    @ColumnInfo(name = "name") var name: String = "Default name",
    @ColumnInfo(name = "status") var status: String = "Default status",
    @ColumnInfo(name = "size") var size: Int = 0,
    @ColumnInfo(name = "location") var location: String = "Default location",
    @ColumnInfo(name = "usage") var usage: Int = 0
)