package com.example.testappnavidrawer

import android.content.Intent
import android.os.Bundle
import androidx.navigation.findNavController
import androidx.navigation.ui.AppBarConfiguration
import androidx.navigation.ui.navigateUp
import androidx.navigation.ui.setupActionBarWithNavController
import androidx.navigation.ui.setupWithNavController
import androidx.drawerlayout.widget.DrawerLayout
import com.google.android.material.navigation.NavigationView
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import android.view.Menu
import android.view.MenuItem
import androidx.preference.PreferenceManager
import android.view.View
import android.widget.Button


class MainActivity : AppCompatActivity() {

    private lateinit var appBarConfiguration: AppBarConfiguration
    var darkTheme = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        PreferenceManager.setDefaultValues(this, R.xml.preferences, true)

        //setTheme(android.R.style.Theme_Black)

        setContentView(R.layout.activity_main)
        val toolbar: Toolbar = findViewById(R.id.toolbar)
        setSupportActionBar(toolbar)

        /*
        val fab: FloatingActionButton = findViewById(R.id.fab)
        fab.setOnClickListener { view ->
            Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show()
        }
        */
        val drawerLayout: DrawerLayout = findViewById(R.id.drawer_layout)
        val navView: NavigationView = findViewById(R.id.nav_view)
        val navController = findNavController(R.id.nav_host_fragment)
        // Passing each menu ID as a set of Ids because each
        // menu should be considered as top level destinations.
        appBarConfiguration = AppBarConfiguration(
            setOf(
                R.id.nav_home, R.id.nav_gallery, R.id.nav_slideshow,
                R.id.nav_tools, R.id.nav_share, R.id.nav_send, R.id.unused
            ), drawerLayout
        )
        setupActionBarWithNavController(navController, appBarConfiguration)
        navView.setupWithNavController(navController)
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.main, menu)
        return true
    }

    override fun onSupportNavigateUp(): Boolean {
        val navController = findNavController(R.id.nav_host_fragment)
        return navController.navigateUp(appBarConfiguration) || super.onSupportNavigateUp()
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_settings -> {
                val intent = Intent(applicationContext, SettingsActivity::class.java)
                startActivity(intent)
                //Snackbar.make(applicationContext, "Replace with your own action", Snackbar.LENGTH_LONG)
                //    .setAction("Action", null).show()
                true
            }

            R.id.refresh_entities -> {
                finish()
                startActivity(intent)
                true
            }

            R.id.activity_2 -> {
                //Snackbar.make(window.decorView, "Replace with your own action", Snackbar.LENGTH_LONG)
                //    .setAction("Action", null).show()
                val intent = Intent(applicationContext, Activity2::class.java)
                startActivity(intent)
                true
            }

            R.id.activity_3 -> {
                //Snackbar.make(window.decorView, "Replace with your own action", Snackbar.LENGTH_LONG)
                //    .setAction("Action", null).show()
                val intent = Intent(applicationContext, Activity3::class.java)
                startActivity(intent)
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    override fun onResume() {
        super.onResume()
        val prefs = PreferenceManager.getDefaultSharedPreferences(this)
        if (prefs.getBoolean("darktheme", false)) {
            darkTheme = true
            val play = findViewById<Button>(R.id.login_button)
            play.isClickable=true
            play.visibility= View.VISIBLE // v letter should be capital
            //Snackbar.make(window.decorView.rootView, "Replace with your own action", Snackbar.LENGTH_LONG)
             //   .setAction("Action", null).show()
            //setTheme(android.R.style.Theme_Black)
            //this.recreate()
        } else {
            //setTheme(android.R.style.Theme_Light)
            //this.recreate()
            darkTheme = false
            val play = findViewById<Button>(R.id.login_button)
            play.isClickable=false
            play.visibility= View.INVISIBLE // v letter should be capital
            //this.recreate()
        }
    }
}
