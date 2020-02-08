package com.example.testappnavidrawer.adapters

import android.annotation.SuppressLint
import android.content.Context
import android.net.ConnectivityManager
import android.os.Handler
import android.os.Looper
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.RecyclerView
import androidx.room.RoomDatabase
import com.example.testappnavidrawer.R
import com.example.testappnavidrawer.model.AppDatabase
import com.example.testappnavidrawer.model.TaxiCompany
import com.example.testappnavidrawer.networking.NetworkAPIAdapter
import com.google.android.material.snackbar.Snackbar
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import okhttp3.ResponseBody
import org.json.JSONObject
import retrofit2.HttpException

class Adapter2(var db: AppDatabase, val companyList: ArrayList<TaxiCompany>, val context: Context) : RecyclerView.Adapter<Adapter2.ViewHolder>() {

    val client by lazy { NetworkAPIAdapter.instance }
    init {
        /*
        val mainHandler = Handler(Looper.getMainLooper())
        mainHandler.post(object : Runnable {
            @SuppressLint("CheckResult")
            override fun run() {
                Toast.makeText(context, "Called", Toast.LENGTH_LONG).show()

                if (checkOnline()) {
                    val serverList = client.getAll()
                    val localList = ArrayList(db.taxiCompany().getAll())

                    if (NetworkAPIAdapter.serverNeedsToBeUpdated) {
                        NetworkAPIAdapter.serverNeedsToBeUpdated = false
                        for (tc in serverList) {
                            client.delete(tc.id.toString())
                                .subscribeOn(Schedulers.io())
                                .observeOn(AndroidSchedulers.mainThread())
                                .subscribe( {}, {}, {
                                    // Toast.makeText(context, "", Toast.LENGTH_LONG)
                                    //   .show()
                                })
                        }

                        for (tc in companyList) {
                            client.insert(tc)
                                .subscribeOn(Schedulers.io())
                                .observeOn(AndroidSchedulers.mainThread())
                                .subscribe( {}, {}, {
                                    // Toast.makeText(context, "Updated online!", Toast.LENGTH_LONG)
                                    //   .show()
                                })
                        }
                    } else {
                        /*companyList.clear()
                        db.taxiCompany().deleteAll()

                        for (tc in serverList) {
                            companyList.add(tc)
                            db.taxiCompany().insertAll(tc)
                        }*/

                        //Toast.makeText(context, "Updated local list with server items", Toast.LENGTH_LONG).show()

                        notifyDataSetChanged()
                    }
                }

                mainHandler.postDelayed(this, 5000)
            }
        })*/
    }

    //this method is returning the view for each item in the list
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): Adapter2.ViewHolder {
        val v = LayoutInflater.from(parent.context).inflate(R.layout.adapter2_layout, parent, false)
        return ViewHolder(v)
    }

    //this method is binding the data on the list
    override fun onBindViewHolder(holder: Adapter2.ViewHolder, position: Int) {
        holder.bindItems(companyList[position])

        holder.itemView.setOnClickListener { view ->

            val builder = AlertDialog.Builder(view.context)
            builder.setTitle("Delete")
            builder.setMessage("Do you want to delete this item?")

            builder.setNegativeButton("Cancel") { _, _ ->
                Toast.makeText(view.context.applicationContext,
                    android.R.string.no, Toast.LENGTH_SHORT).show()
            }

            builder.setNeutralButton("Delete") { _, _ ->
                if (checkOnline()) {
                    // Make progressbar visible for a second
                    //progressBar.visibility = View.VISIBLE
                    //Handler().postDelayed({
                    //    progressBar.visibility = View.INVISIBLE
                    //}, 1000)

                    Log.d("[CRUD]", "Deleted online id = " + companyList[position].id.toString())
                    //Toast.makeText(context, "Deleting online!", Toast.LENGTH_LONG)
                    //    .show()

                    var companyId = companyList[position].id

                    db.taxiCompany().delete(companyList[position])
                    companyList.removeAt(position)

                    client.delete(companyId.toString())
                        .subscribeOn(Schedulers.io())
                        .observeOn(AndroidSchedulers.mainThread())
                        .subscribe( {}, {}, {
                            //Toast.makeText(context, "DELETE DONE!", Toast.LENGTH_LONG)
                            //   .show()
                        })
                } else {
                    //NetworkAPIAdapter.serverNeedsToBeUpdated = true
                    Log.d("[CRUD]", "Not online, cannot delete!")
                    Toast.makeText(context, "Not online, cannot delete!", Toast.LENGTH_LONG).show()
                }


                notifyDataSetChanged()
            }
            builder.show()
        }
    }

    // Hacky way of returning a value from globalscope.launch, lol
    var somevar: Int = 0

    // Return the size of the list
    override fun getItemCount(): Int {
        return companyList.size
        //GlobalScope.launch { somevar = db.taxiCompany().getAll().size }

        //return somevar
    }

    //the class is holding the list view
    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

        fun bindItems(company: TaxiCompany) {
            val id = itemView.findViewById(R.id.id) as TextView
            val name = itemView.findViewById(R.id.name) as TextView
            val status  = itemView.findViewById(R.id.status) as TextView
            val size = itemView.findViewById(R.id.size) as TextView
            val location = itemView.findViewById(R.id.location) as TextView
            val usage = itemView.findViewById(R.id.usage) as TextView
            id.text = company.id.toString()
            name.text = company.name
            status.text = company.status
            size.text = company.size.toString()
            location.text = company.location
            usage.text = company.usage.toString()
        }
    }

    private fun checkOnline(): Boolean {
        //Toast.makeText(context, "Not online!1", Toast.LENGTH_LONG).show()
        val cm = context.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
        val networkInfo = cm.activeNetworkInfo
        if (networkInfo != null && networkInfo.isConnected) {
            //Toast.makeText(context, "Not online!2", Toast.LENGTH_LONG).show()
            return true
        }
        //Toast.makeText(context, "Not online3", Toast.LENGTH_LONG).show()
        return false

    }
}