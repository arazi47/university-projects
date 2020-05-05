package com.company.view.commands;

import com.company.sorter.ManualSorter;
import com.company.sorter.Sorter;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class OpenPortsCommand extends Command {
    public OpenPortsCommand(String key, String description) {
        super(key, description);
    }

    @Override
    public void execute() {
        System.out.println("Input ports (input -1 to finish):");
        Scanner scanner = new Scanner(System.in);
        System.out.print("> ");
        int port = scanner.nextInt();
        List<Integer> ports = new ArrayList<>();
        do {
            ports.add(port);
            System.out.print("> ");
            port = scanner.nextInt();
        } while (port != -1);

        Sorter sorter = new ManualSorter();
        sorter.sort(ports);
        System.out.println("The following ports are now opened: " + ports);
    }
}
