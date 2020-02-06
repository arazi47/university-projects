package com.example.testappnavidrawer

import android.os.Bundle
import android.os.Handler
import android.os.StrictMode
import android.view.View
import android.widget.ProgressBar
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.testappnavidrawer.adapters.Adapter2
import com.example.testappnavidrawer.adapters.Adapter3
import com.example.testappnavidrawer.networking.NetworkAPIAdapter

import kotlinx.android.synthetic.main.activity_3.*

class Activity3 : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_3)
        setSupportActionBar(toolbar)

        val progressBar = findViewById<ProgressBar>(R.id.indeterminateBar)
        progressBar.bringToFront()

        fab.setOnClickListener { view ->
            //Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
            //    .setAction("Action", null).show()
            // Make progressbar visible for a second
            progressBar.visibility = View.VISIBLE
            Handler().postDelayed({
                progressBar.visibility = View.INVISIBLE
            }, 1000)
            finish()
            startActivity(intent)
        }

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

        //creating our adapter
        val adapter = Adapter3(taxiCompanies, window.context)

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi JMEK", "Comp address", "0712321232"))

        val recyclerView = findViewById(R.id.recyclerView) as RecyclerView

        recyclerView.layoutManager = LinearLayoutManager(window.context, RecyclerView.VERTICAL, false)

        //now adding the adapter to recyclerview
        recyclerView.adapter = adapter

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi DUPA ADAPTER", "Comp address", "0712321232"))


        /*val addBtn: FloatingActionButton = findViewById(R.id.addBtn)
        addBtn.setOnClickListener { view ->
            val dialog = LayoutInflater.from(window.context).inflate(R.layout.add_taxi_company_dialog, null);
            val builder = AlertDialog.Builder(window.context)
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
                //db.taxiCompany().insertAll(taxiCompany)

                if (checkOnline()) {
                    client.insert(taxiCompany)
                        .subscribeOn(Schedulers.io())
                        .observeOn(AndroidSchedulers.mainThread())
                        .subscribe({}, {}, {
                            Toast.makeText(window.context, "Inserted online", Toast.LENGTH_LONG)
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
        }*/
    }

    private fun checkOnline(): Boolean {
        return true
        /*

        //Toast.makeText(context, "Not online!1", Toast.LENGTH_LONG).show()
        val cm = this.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val networkInfo = cm.activeNetworkInfo
        if (networkInfo != null && networkInfo.isConnected) {
            //Toast.makeText(context, "Not online!2", Toast.LENGTH_LONG).show()
            return true
        }
        //Toast.makeText(context, "Not online3", Toast.LENGTH_LONG).show()
        return false*/

    }

}
