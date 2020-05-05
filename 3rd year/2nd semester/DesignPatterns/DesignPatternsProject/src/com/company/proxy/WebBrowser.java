package com.company.proxy;

/**
 * Proxy design pattern (structural): to connect to the school's internet,
 * first go through ProxyWebBrowser that checks if the student
 * is allowed to go to the specified website.
 */
public interface WebBrowser {
    void goToWebsite(String url) throws Exception;
}
