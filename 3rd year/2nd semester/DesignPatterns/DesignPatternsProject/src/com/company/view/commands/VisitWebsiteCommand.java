package com.company.view.commands;

import com.company.proxy.ProxyWebConnection;

import java.util.Scanner;

public class VisitWebsiteCommand extends Command {
    public VisitWebsiteCommand(String key, String description) {
        super(key, description);
    }

    @Override
    public void execute() {
        ProxyWebConnection connection = new ProxyWebConnection();
        System.out.print("Enter URL: ");
        Scanner scanner = new Scanner(System.in);
        String url = scanner.nextLine();
        try {
            connection.goToWebsite(url);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
