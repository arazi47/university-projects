package com.example.testappnavidrawer

import android.content.Context
import android.net.ConnectivityManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.StrictMode
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.widget.ProgressBar
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.room.Room
import com.example.testappnavidrawer.adapters.Adapter2
import com.example.testappnavidrawer.adapters.TaxiCompaniesAdapter
import com.example.testappnavidrawer.model.AppDatabase
import com.example.testappnavidrawer.model.TaxiCompany
import com.example.testappnavidrawer.networking.NetworkAPIAdapter
import com.example.testappnavidrawer.ui.home.guid
import com.facebook.CallbackManager
import com.facebook.FacebookCallback
import com.facebook.FacebookException
import com.facebook.login.LoginResult
import com.facebook.login.widget.LoginButton
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.google.android.material.snackbar.Snackbar
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.activity_2.*
import kotlinx.android.synthetic.main.activity_3.*
import kotlinx.android.synthetic.main.activity_3.fab
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*

class Activity2 : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_2)

        val progressBar = findViewById<ProgressBar>(R.id.indeterminateBar)
        progressBar.bringToFront()

        /*
        fab.setOnClickListener { view ->
            //Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
            //    .setAction("Action", null).show()
            // Make progressbar visible for a second
            progressBar.visibility = View.VISIBLE
            Handler().postDelayed({
                progressBar.visibility = View.INVISIBLE
            }, 1000)
            //finish()
            //startActivity(intent)
        }
        */

        // allow network calls on main thread
        val policy = StrictMode.ThreadPolicy.Builder()
            .permitAll().build()
        StrictMode.setThreadPolicy(policy)

        val client = NetworkAPIAdapter.instance
        //var taxiCompanies = null
        //if (checkOnline())
        var taxiCompanies = ArrayList(client.getAll())

        //db.taxiCompany().deleteAll()
        //for (tc in taxiCompanies)
        //    db.taxiCompany().insertAll(tc)
        //val root = inflater.inflate(R.layout.activity_2, container, false)

        val db = Room.databaseBuilder(
            this,
            AppDatabase::class.java, "maindb1_1_1.db"
        ).allowMainThreadQueries().build()

        //creating our adapter
        val adapter = Adapter2(db, taxiCompanies, window.context)

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi JMEK", "Comp address", "0712321232"))

        val recyclerView = findViewById(R.id.recyclerView) as RecyclerView

        recyclerView.layoutManager = LinearLayoutManager(window.context, RecyclerView.VERTICAL, false)

        //now adding the adapter to recyclerview
        recyclerView.adapter = adapter

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi DUPA ADAPTER", "Comp address", "0712321232"))


        fab.setOnClickListener { view ->
            //Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
            //    .setAction("Action", null).show()
            // Make progressbar visible for a second
            progressBar.visibility = View.VISIBLE
            Handler().postDelayed({
                progressBar.visibility = View.INVISIBLE
            }, 1000)
            //finish()
            //startActivity(intent)
            if (checkOnline()) {
                adapter.companyList.clear()
                var newList = ArrayList(client.getAll())
                newList.sortByDescending { it.usage }
                adapter.companyList.addAll(newList.take(10)) // insert top 10
                Log.d("[TOP]", "Top 10 list")
                adapter.notifyDataSetChanged()
            } else {
                Log.d("[TOP]", "Phone is not connected to the internet")
                Snackbar.make(view, "Not online, sorry", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show()
            }
        }

        getFileListBtn.setOnClickListener { view ->
            progressBar.visibility = View.VISIBLE
            Handler().postDelayed({
                progressBar.visibility = View.INVISIBLE
            }, 1000)
            var lst = client.getAllLocations()
            Snackbar.make(view, lst.toString(), Snackbar.LENGTH_SHORT)
                .setAction("Action", null).show()
        }
    }

    private fun checkOnline(): Boolean {
        //return true


        //Toast.makeText(context, "Not online!1", Toast.LENGTH_LONG).show()
        val cm = this.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val networkInfo = cm.activeNetworkInfo
        if (networkInfo != null && networkInfo.isConnected) {
            //Toast.makeText(context, "Not online!2", Toast.LENGTH_LONG).show()
            return true
        }
        //Toast.makeText(context, "Not online3", Toast.LENGTH_LONG).show()
        return false

    }
}
