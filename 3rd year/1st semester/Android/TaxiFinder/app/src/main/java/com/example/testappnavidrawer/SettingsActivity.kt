package com.example.testappnavidrawer

import android.app.PendingIntent.getActivity
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.preference.PreferenceFragmentCompat
import androidx.preference.PreferenceManager
import android.content.SharedPreferences



class SettingsActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.settings_activity)
        supportFragmentManager
            .beginTransaction()
            .replace(R.id.settings, SettingsFragment())
            .commit()
        supportActionBar?.setDisplayHomeAsUpEnabled(true)
    }

    class SettingsFragment : PreferenceFragmentCompat() {
        override fun onCreatePreferences(savedInstanceState: Bundle?, rootKey: String?) {
            setPreferencesFromResource(R.xml.preferences, rootKey)
            /*
            val listener = SharedPreferences.OnSharedPreferenceChangeListener { prefs, key ->
                /*
                if (prefs.getBoolean("dark_theme", false))
                    setTheme(android.R.style.Theme_Black)
                else
                    setTheme(android.R.style.Theme_Black)
                */

            }

            PreferenceManager.getDefaultSharedPreferences(activity).registerOnSharedPreferenceChangeListener(listener)
            */
        }
    }
}