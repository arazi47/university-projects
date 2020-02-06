package com.example.testappnavidrawer.networking

import android.util.Log
import com.example.testappnavidrawer.model.TaxiCompany
import com.google.gson.FieldNamingPolicy
import com.google.gson.Gson
import com.google.gson.GsonBuilder
import io.reactivex.Observable
import io.reactivex.schedulers.Schedulers
import okhttp3.ResponseBody
import retrofit2.Call
import retrofit2.Retrofit
import retrofit2.adapter.rxjava2.RxJava2CallAdapterFactory
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.*

class NetworkAPIAdapter private constructor() {

    private object Holder {
        val INSTANCE = NetworkAPIAdapter()
    }

    companion object {
        val instance: NetworkAPIAdapter by lazy { Holder.INSTANCE }
        var serverNeedsToBeUpdated: Boolean = false
        const val BASE_URL: String = "http://10.0.2.2:2024"
        private const val URL_ORDERS_ALL: String = "/get"
        private const val URL_ADD_COMPANY: String = "/addcompany"
        private const val URL_UPDATE_INDIVIDUAL: String = "/update"
        private const val URL_DELETE_INDIVIDUAL: String = "/delete/{id}"
    }

    private val bookService: BooksService

    init {
        val gson: Gson = GsonBuilder()
            .setFieldNamingPolicy(FieldNamingPolicy.LOWER_CASE_WITH_UNDERSCORES).create()

        val retrofit: Retrofit = Retrofit.Builder()
            .baseUrl(BASE_URL)
            .addConverterFactory(GsonConverterFactory.create(gson))
            .addCallAdapterFactory(RxJava2CallAdapterFactory.createWithScheduler(Schedulers.io()))
            .build()

        bookService = retrofit.create(BooksService::class.java)
    }

    fun getAll(): List<TaxiCompany> {
        return bookService.fetchAll().execute().body()!!
    }

    fun insert(dto: TaxiCompany): Observable<TaxiCompany> {
        //Log.d("INSERT", dto.toString())
        return bookService.insert(dto)
    }

    fun update(dto: TaxiCompany): Observable<ResponseBody> {
        return bookService.update(dto)
    }

    fun delete(id: String): Observable<ResponseBody> {
        return bookService.delete(id)
    }

    interface BooksService {
        @GET(URL_ORDERS_ALL)
        fun fetchAll(): Call<List<TaxiCompany>>

        @POST(URL_ADD_COMPANY)
        //@FormUrlEncoded
        fun insert(@Body tc: TaxiCompany): Observable<TaxiCompany>

        @PUT(URL_UPDATE_INDIVIDUAL)
        //@FormUrlEncoded
        fun update(@Body tc: TaxiCompany): Observable<ResponseBody>

        @DELETE(URL_DELETE_INDIVIDUAL)
        fun delete(@Path("id") id: String): Observable<ResponseBody>
    }
}