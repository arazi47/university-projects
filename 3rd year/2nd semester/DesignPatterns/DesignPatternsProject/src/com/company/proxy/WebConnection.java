package com.company.proxy;

/**
 * Proxy design pattern: to connect to the school's internet,
 * first go through ProxyWebConnection that checks if the student
 * is allowed to go to the specified website.
 */
public interface WebConnection {
    void goToWebsite(String url) throws Exception;
}
