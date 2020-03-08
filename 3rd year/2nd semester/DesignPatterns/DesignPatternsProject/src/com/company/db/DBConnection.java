package com.company.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {
    private static Connection connection;

    private static void connect() {
        if (connection == null) {
            String url = "jdbc:mysql//localhost:3306/designpatterns";
            try {
                Class.forName("com.mysql.jdbc.driver");
                connection = DriverManager.getConnection(url, "root", "root1234");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void disconnect() {
        try {
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        connection = null;
    }

    public static Connection getConnection() {
        if (connection == null)
            connect();

        return connection;
    }
}
