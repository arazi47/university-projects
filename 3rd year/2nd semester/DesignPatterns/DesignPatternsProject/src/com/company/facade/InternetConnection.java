package com.company.facade;

import com.company.logger.Logger;

import java.io.IOException;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;

public class InternetConnection {
    private boolean port80Opened = false;
    private boolean internetConnected = false;

    public boolean isPort80Opened() {
        if (port80Opened)
            return true;

        try (Socket ignored = new Socket("localhost", 80)) {
            return false;
        } catch (IOException ignored) {
            this.port80Opened = true;
            return true;
        }
    }

    public boolean isInternetConnected() {
        if (internetConnected)
            return true;

        try {
            URL url = new URL("http://www.google.co1m");
            URLConnection connection = url.openConnection();
            connection.connect();
            this.port80Opened = true;
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public void openPort80() {
        Logger.log("Successfully opened port " + 80);
        port80Opened = true;
    }

    public void connectToInternet() {
        this.internetConnected = true;
        Logger.log("Successfully activated internet");
    }
}
