package com.example.taxifinder

import android.os.Bundle
import android.view.LayoutInflater
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.taxifinder.adapters.TaxiCompaniesAdapter
import com.example.taxifinder.model.TaxiCompany

import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //setSupportActionBar(toolbar)

        val recyclerView = findViewById(R.id.recyclerView) as RecyclerView

        recyclerView.layoutManager = LinearLayoutManager(this, RecyclerView.VERTICAL, false)

        val taxiCompanies = ArrayList<TaxiCompany>()

        //adding some dummy data to the list
        taxiCompanies.add(TaxiCompany("0", "Taxi STAR", "Str. Teodor Mihali nr. 1", "0712321232"))
        taxiCompanies.add(TaxiCompany("1", "Taxi PLUS", "Str. B.P. Hasdeu nr. 58-60", "0712321232"))
        taxiCompanies.add(TaxiCompany("2", "Taxi JMEK", "Str. Roman Ciorogariu nr. 18", "0712321232"))

        //creating our adapter
        val adapter = TaxiCompaniesAdapter(taxiCompanies)

        taxiCompanies.add(TaxiCompany("3", "Taxi JMEK", "Comp address", "0712321232"))

        //now adding the adapter to recyclerview
        recyclerView.adapter = adapter

        taxiCompanies.add(TaxiCompany("4", "Taxi DUPA ADAPTER", "Comp address", "0712321232"))

        addBtn.setOnClickListener { view ->
            /*Snackbar.make(view, "Taxi added", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show()
            taxiCompanies.add(TaxiCompany("5", "Taxi JMEK", "Comp address", "0712321232"))
            adapter.notifyDataSetChanged();*/

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
                taxiCompanies.add(TaxiCompany("9", companyName, companyAddress, companyPhoneNumber))
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
}
