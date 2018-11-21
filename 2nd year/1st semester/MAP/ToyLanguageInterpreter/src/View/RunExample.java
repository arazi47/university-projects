package View;

import Controller.InterpreterController;

public class RunExample extends Command {
    private InterpreterController ctrl;

    RunExample(String key, String desc, InterpreterController ctrl){
        super(key, desc);
        this.ctrl = ctrl;
    }

    @Override
    public void execute() throws java.lang.InterruptedException {
        /*
        try {
            System.out.println(this.ctrl.getRepo().getCurrentPs());
            ctrl.executeAll();
            System.out.println(this.ctrl.getRepo().getCurrentPs());
        }
        catch (Exception e) {
            System.out.println(e.toString());
        }
        */

        //this.ctrl.getRepo().getProgramStates().forEach(prg -> System.out.println(prg.toString()));
        this.ctrl.executeAllSteps();
        //this.ctrl.getRepo().getProgramStates().forEach(prg -> System.out.println(prg.toString()));
    }
}
