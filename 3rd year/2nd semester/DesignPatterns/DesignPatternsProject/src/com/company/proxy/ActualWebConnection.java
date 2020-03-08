package com.company.proxy;

import com.company.logger.Logger;

public class ActualWebConnection implements WebConnection {
    @Override
    public void goToWebsite(String url) throws Exception {
        System.out.println("Connected to " + url);
        Logger.log("A student connected to " + url);
    }
}
