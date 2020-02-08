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

class Adapter3(val companyList: ArrayList<TaxiCompany>, val context: Context) : RecyclerView.Adapter<Adapter3.ViewHolder>() {

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
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): Adapter3.ViewHolder {
        val v = LayoutInflater.from(parent.context).inflate(R.layout.adapter3_layout, parent, false)
        return ViewHolder(v)
    }

    //this method is binding the data on the list
    override fun onBindViewHolder(holder: Adapter3.ViewHolder, position: Int) {
        holder.bindItems(companyList[position])
        //GlobalScope.launch {
        //    holder.bindItems(db.taxiCompany().getAll()[position])
        //}

        /*
        holder.itemView.setOnClickListener { view ->

            val builder = AlertDialog.Builder(view.context)
            builder.setTitle("Update or delete")
            builder.setMessage("Do you want to update or delete this item?")

            builder.setPositiveButton("Update") { _, _ ->
                Toast.makeText(view.context.applicationContext,
                    android.R.string.yes, Toast.LENGTH_SHORT).show()


                val dialog = LayoutInflater.from(view.context).inflate(R.layout.add_taxi_company_dialog, null);
                val myBuilder = AlertDialog.Builder(view.context)
                    .setView(dialog)
                    .setTitle("Update taxi company")

                val alertDialog = myBuilder.show()

                //dialog.companyName.setText(db.taxiCompany().getAll()[position].name)
                //dialog.companyPhoneNumber.setText(db.taxiCompany().getAll()[position].phoneNumber)
                //dialog.companyAddress.setText(db.taxiCompany().getAll()[position].address)

                dialog.addTaxiCompanyOkBtn.setOnClickListener {
                    alertDialog.dismiss()

                    if (checkOnline()) {
                        companyList[position].name =
                            dialog.companyName.text.toString()
                        companyList[position].phoneNumber =
                            dialog.companyPhoneNumber.text.toString()
                        companyList[position].address =
                            dialog.companyAddress.text.toString()

                        //db.taxiCompany().updateTaxiCompany(companyList[position])

                        //Toast.makeText(context, "You are online, updating", Toast.LENGTH_LONG).show()
                        client.update(companyList[position])
                            .subscribeOn(Schedulers.io())
                            .observeOn(AndroidSchedulers.mainThread())
                            .subscribe( {}, {}, {
                                Toast.makeText(context, "Updated online!", Toast.LENGTH_LONG)
                                    .show()
                            })
                    } else {
                        //NetworkAPIAdapter.serverNeedsToBeUpdated = true
                        Toast.makeText(context, "Not online, cannot update!", Toast.LENGTH_LONG).show()
                    }

                    notifyDataSetChanged()
                }

                dialog.addTaxiCompanyCancelBtn.setOnClickListener {
                    alertDialog.dismiss()
                }
            }

            builder.setNegativeButton("Cancel") { _, _ ->
                Toast.makeText(view.context.applicationContext,
                    android.R.string.no, Toast.LENGTH_SHORT).show()
            }

            builder.setNeutralButton("Delete") { _, _ ->
                if (checkOnline()) {
                    //Toast.makeText(context, "Deleting online!", Toast.LENGTH_LONG)
                    //    .show()

                    //db.taxiCompany().delete(companyList[position])
                    companyList.removeAt(position)

                    client.delete(companyList[position].id.toString())
                        .subscribeOn(Schedulers.io())
                        .observeOn(AndroidSchedulers.mainThread())
                        .subscribe( {}, {}, {
                            //Toast.makeText(context, "DELETE DONE!", Toast.LENGTH_LONG)
                            //   .show()
                        })
                } else {
                    //NetworkAPIAdapter.serverNeedsToBeUpdated = true
                    Toast.makeText(context, "Not online, cannot delete!", Toast.LENGTH_LONG).show()
                }


                notifyDataSetChanged()
            }
            builder.show()
        }*/
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
            /*
            val textViewName = itemView.findViewById(R.id.textViewCompanyName) as TextView
            val textViewPhoneNumber  = itemView.findViewById(R.id.textViewCompanyPhoneNumber) as TextView
            val textViewCompanyAddress = itemView.findViewById(R.id.textViewCompanyAddress) as TextView
            textViewName.text = company.name
            textViewPhoneNumber.text = company.phoneNumber
            textViewCompanyAddress.text = company.address*/
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