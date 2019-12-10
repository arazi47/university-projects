package com.example.taxifinder

import android.content.Context
import android.net.ConnectivityManager
import android.os.Bundle
import android.provider.Settings
import android.view.LayoutInflater
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.room.Room
import com.example.taxifinder.adapters.TaxiCompaniesAdapter
import com.example.taxifinder.model.AppDatabase
import com.example.taxifinder.model.TaxiCompany
import com.example.taxifinder.networking.NetworkAPIAdapter

import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.*
import org.json.JSONObject
import java.util.concurrent.TimeUnit
import android.os.StrictMode
import android.widget.Toast
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.schedulers.Schedulers


var guid = 0

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //setSupportActionBar(toolbar)

        val recyclerView = findViewById(R.id.recyclerView) as RecyclerView

        recyclerView.layoutManager = LinearLayoutManager(this, RecyclerView.VERTICAL, false)

        val db = Room.databaseBuilder(
            applicationContext,
            AppDatabase::class.java, "maindb1_1.db"
        ).allowMainThreadQueries().build()

       // GlobalScope.launch {
        //launch(Dispatchers.Default) {
/*            db.taxiCompany().insertAll(
                TaxiCompany(
                    guid++,
                    "Taxi STAR",
                    "Str. Teodor Mihali nr. 1",
                    "0712321232"
                )
            )*/
       // }
        //}

        // allow network calls on main thread
        val policy = StrictMode.ThreadPolicy.Builder()
            .permitAll().build()
        StrictMode.setThreadPolicy(policy)

        val client = NetworkAPIAdapter.instance
        var taxiCompanies = ArrayList(db.taxiCompany().getAll())
        if (checkOnline())
            taxiCompanies = ArrayList(client.getAll())

        //val testtc = TaxiCompany(guid++, "Taxi STAR", "Str. Teodor Mihali nr. 1", "0712321232")
        //client.insert(testtc)
        //client.update("1", testtc)
        //client.delete("1")

        // First sync server && local persistence
        //db.taxiCompany().deleteAll()
        //for (tc in taxiCompanies) {
        //    db.taxiCompany().insertAll(tc)
        //    guid = tc.id
        //}

        //++guid

        //val taxiCompanies = ArrayList<TaxiCompany>(db.taxiCompany().getAll())

        //adding some dummy data to the list
        //taxiCompanies.add(TaxiCompany(guid++, "Taxi STAR", "Str. Teodor Mihali nr. 1", "0712321232"))
        //taxiCompanies.add(TaxiCompany(guid++, "Taxi PLUS", "Str. B.P. Hasdeu nr. 58-60", "0712321232"))
        //taxiCompanies.add(TaxiCompany(guid++, "Taxi JMEK", "Str. Roman Ciorogariu nr. 18", "0712321232"))

        //creating our adapter
        val adapter = TaxiCompaniesAdapter(db, taxiCompanies, this)

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi JMEK", "Comp address", "0712321232"))

        //now adding the adapter to recyclerview
        recyclerView.adapter = adapter

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi DUPA ADAPTER", "Comp address", "0712321232"))

        addBtn.setOnClickListener { view ->
            val dialog = LayoutInflater.from(this).inflate(R.layout.add_taxi_company_dialog, null);
            val builder = AlertDialog.Builder(this)
                .setView(dialog)
                .setTitle("Add taxi company")

            val alertDialog = builder.show()

            dialog.addTaxiCompanyOkBtn.setOnClickListener {
                alertDialog.dismiss()
                val companyName = dialog.companyName.text.toString()
                val companyPhoneNumber = dialog.companyPhoneNumber.text.toString()
                val companyAddress = dialog.companyAddress.text.toString()
                val taxiCompany = TaxiCompany(guid++, companyName, companyAddress, companyPhoneNumber)
                taxiCompanies.add(taxiCompany)
                db.taxiCompany().insertAll(taxiCompany)

                if (checkOnline()) {
                    client.insert(taxiCompany)
                        .subscribeOn(Schedulers.io())
                        .observeOn(AndroidSchedulers.mainThread())
                        .subscribe({}, {}, {
                            Toast.makeText(this, "Inserted online", Toast.LENGTH_LONG)
                                .show()
                        })
                } else {
                    NetworkAPIAdapter.serverNeedsToBeUpdated = true
                }

                adapter.notifyDataSetChanged()
            }

            dialog.addTaxiCompanyCancelBtn.setOnClickListener {
                alertDialog.dismiss()
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }

    private fun checkOnline(): Boolean {
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
