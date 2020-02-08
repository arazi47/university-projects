package com.example.testappnavidrawer.ui.home

import android.content.Context
import android.net.ConnectivityManager
import android.os.Bundle
import android.os.Handler
import android.os.StrictMode
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ProgressBar
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProviders
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.room.Room
import com.example.testappnavidrawer.R
import com.example.testappnavidrawer.adapters.TaxiCompaniesAdapter
import com.example.testappnavidrawer.model.AppDatabase
import com.example.testappnavidrawer.model.TaxiCompany
import com.example.testappnavidrawer.networking.NetworkAPIAdapter
import com.facebook.CallbackManager
import com.facebook.FacebookCallback
import com.facebook.FacebookException
import com.facebook.login.LoginResult
import com.facebook.login.widget.LoginButton
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.google.android.material.snackbar.Snackbar
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*

var guid = 101

class HomeFragment : Fragment() {

    private lateinit var homeViewModel: HomeViewModel

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        homeViewModel =
            ViewModelProviders.of(this).get(HomeViewModel::class.java)
        val root = inflater.inflate(R.layout.fragment_home, container, false)
        /*val textView: TextView = root.findViewById(R.id.text_home)
        homeViewModel.text.observe(this, Observer {
            textView.text = it
        })*/

        val progressBar = root.findViewById(R.id.indeterminateBar) as ProgressBar
        progressBar.bringToFront()
        // Make progressbar visible for a second
        progressBar.visibility = View.VISIBLE
        Handler().postDelayed({
            progressBar.visibility = View.INVISIBLE
        }, 3000)

        val recyclerView = root.findViewById(R.id.recyclerView) as RecyclerView

        recyclerView.layoutManager = LinearLayoutManager(root.context, RecyclerView.VERTICAL, false)

        val db = Room.databaseBuilder(
            root.context,
            AppDatabase::class.java, "maindb1_1_1.db"
        ).allowMainThreadQueries().build()

        // allow network calls on main thread
        val policy = StrictMode.ThreadPolicy.Builder()
            .permitAll().build()
        StrictMode.setThreadPolicy(policy)

        val client = NetworkAPIAdapter.instance
        var taxiCompanies = ArrayList(db.taxiCompany().getAll())
        if (checkOnline())
            taxiCompanies = ArrayList(client.getAll())
        else {
            Snackbar.make(root, "Not connected to the internet, sorry", Snackbar.LENGTH_LONG)
               .setAction("Action", null).show()
        }

        db.taxiCompany().deleteAll()
        for (tc in taxiCompanies)
            db.taxiCompany().insertAll(tc)

        //creating our adapter
        val adapter = TaxiCompaniesAdapter(db, taxiCompanies, root.context, progressBar)

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi JMEK", "Comp address", "0712321232"))

        //now adding the adapter to recyclerview
        recyclerView.adapter = adapter

        //taxiCompanies.add(TaxiCompany(guid++, "Taxi DUPA ADAPTER", "Comp address", "0712321232"))

        val addBtn: FloatingActionButton = root.findViewById(R.id.addBtn)
        addBtn.setOnClickListener { view ->
            val dialog = LayoutInflater.from(root.context).inflate(R.layout.add_taxi_company_dialog, null);
            val builder = AlertDialog.Builder(root.context)
                .setView(dialog)
                .setTitle("Record file")

            val alertDialog = builder.show()

            dialog.addTaxiCompanyOkBtn.setOnClickListener {
                alertDialog.dismiss()

                // Make progressbar visible for a second
                progressBar.visibility = View.VISIBLE
                Handler().postDelayed({
                    progressBar.visibility = View.INVISIBLE
                }, 1000)

                val inputName = dialog.inputName.text.toString()
                val inputStatus = dialog.inputStatus.text.toString()
                val inputSize = Integer.parseInt(dialog.inputSize.text.toString())
                val inputLocation = dialog.inputLocation.text.toString()
                //val inputUsage = Integer.parseInt(dialog.inputSize.text.toString())
                val taxiCompany = TaxiCompany(guid++, inputName, inputStatus, inputSize, inputLocation, 0) // no usages so far
                taxiCompanies.add(taxiCompany)
                db.taxiCompany().insertAll(taxiCompany)

                if (checkOnline()) {
                    client.insert(taxiCompany)
                        .subscribeOn(Schedulers.io())
                        .observeOn(AndroidSchedulers.mainThread())
                        .subscribe({}, {}, {
                            Log.d("[CRUD]", "Inserted online id = ${taxiCompany.id}")
                            Toast.makeText(root.context, "Inserted online ", Toast.LENGTH_LONG)
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

        var callbackManager = CallbackManager.Factory.create()


        val EMAIL = "email"

        var loginButton = root.findViewById<LoginButton>(R.id.login_button)
        loginButton.setReadPermissions(listOf(EMAIL))
        // If you are using in a fragment, call loginButton.setFragment(this);

        // Callback registration
        loginButton.registerCallback(callbackManager, object : FacebookCallback<LoginResult> {
            override fun onSuccess(loginResult: LoginResult) {
                // App code
                //Snackbar.make(view, "Login success", Snackbar.LENGTH_LONG)
                //   .setAction("Action", null).show()
            }

            override fun onCancel() {
                // App code
            }

            override fun onError(exception: FacebookException) {
                // App code
                //Snackbar.make(view, "Login fail", Snackbar.LENGTH_LONG)
                //  .setAction("Action", null).show()
            }
        })

        return root
    }

    private fun checkOnline(): Boolean {
        //Toast.makeText(context, "Not online!1", Toast.LENGTH_LONG).show()

        val cm = activity!!.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val networkInfo = cm.activeNetworkInfo
        if (networkInfo != null && networkInfo.isConnected) {
            //Toast.makeText(context, "Not online!2", Toast.LENGTH_LONG).show()
            return true
        }
        //Toast.makeText(context, "Not online3", Toast.LENGTH_LONG).show()
        return false

    }
}