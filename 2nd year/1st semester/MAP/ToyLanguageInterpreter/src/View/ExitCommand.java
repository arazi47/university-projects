package View;

public class ExitCommand extends Command {
    ExitCommand(String key, String desc){
        super(key, desc);
    }

    @Override
    public void execute() {
        System.exit(0);
    }
}
