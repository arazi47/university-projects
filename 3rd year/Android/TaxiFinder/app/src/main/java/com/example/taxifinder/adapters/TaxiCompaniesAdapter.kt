package com.example.taxifinder.adapters

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AlertDialog
import androidx.recyclerview.widget.RecyclerView
import com.example.taxifinder.R
import com.example.taxifinder.model.TaxiCompany
import com.google.android.material.snackbar.Snackbar
import kotlinx.android.synthetic.main.add_taxi_company_dialog.view.*

class TaxiCompaniesAdapter(val companyList: ArrayList<TaxiCompany>) : RecyclerView.Adapter<TaxiCompaniesAdapter.ViewHolder>() {

    //this method is returning the view for each item in the list
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TaxiCompaniesAdapter.ViewHolder {
        val v = LayoutInflater.from(parent.context).inflate(R.layout.taxicompanies_list_layout, parent, false)
        return ViewHolder(v)
    }

    //this method is binding the data on the list
    override fun onBindViewHolder(holder: TaxiCompaniesAdapter.ViewHolder, position: Int) {
        holder.bindItems(companyList[position])

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

                dialog.companyName.setText(companyList[position].name)
                dialog.companyPhoneNumber.setText(companyList[position].phoneNumber)
                dialog.companyAddress.setText(companyList[position].address)

                dialog.addTaxiCompanyOkBtn.setOnClickListener {
                    alertDialog.dismiss()

                    companyList[position].name = dialog.companyName.text.toString()
                    companyList[position].phoneNumber = dialog.companyPhoneNumber.text.toString()
                    companyList[position].address = dialog.companyAddress.text.toString()
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
                companyList.removeAt(position)
                notifyDataSetChanged()
            }
            builder.show()
        }
    }

    // Return the size of the list
    override fun getItemCount(): Int {
        return companyList.size
    }

    //the class is holding the list view
    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

        fun bindItems(company: TaxiCompany) {
            val textViewName = itemView.findViewById(R.id.textViewCompanyName) as TextView
            val textViewPhoneNumber  = itemView.findViewById(R.id.textViewCompanyPhoneNumber) as TextView
            val textViewCompanyAddress = itemView.findViewById(R.id.textViewCompanyAddress) as TextView
            textViewName.text = company.name
            textViewPhoneNumber.text = company.phoneNumber
            textViewCompanyAddress.text = company.address
        }
    }
}