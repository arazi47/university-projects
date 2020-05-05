package com.company.proxy;

import com.company.facade.InternetConnection;
import com.company.logger.Logger;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProxyWebBrowser implements WebBrowser {
    private List<String> allowedURLs = new ArrayList<>(Arrays.asList("www.wikipedia.com", "www.geeksforgeeks.com"));
    private ActualWebBrowser webConnection = new ActualWebBrowser();
    private InternetConnection internetConnection = new InternetConnection();

    @Override
    public void goToWebsite(String url) throws Exception {
        // Facade
        if (!internetConnection.isInternetConnected()) {
            Logger.log("Internet is not connected!");
            internetConnection.connectToInternet();
        } else {
            Logger.log("Internet connection OK");
        }

        // Proxy
        if (!allowedURLs.contains(url)) {
           Logger.log("A student tried to access a site that is not allowed: " + url);
           return;
        }

        webConnection.goToWebsite(url);
    }
}
