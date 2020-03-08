package com.company.view.commands;

public class ExitCommand extends Command {
    public ExitCommand(String key, String description) {
        super(key, description);
    }

    @Override
    public void execute() {
        System.out.println("Goodbye");
        System.exit(0);
    }
}
