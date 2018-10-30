package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

public class Repo implements IRepo {
    private MyList<ProgramState> programStates;
    private int currentPsIndex ;

    public Repo() {
        this.programStates = new MyList<>();
        this.currentPsIndex = 0;
    }

    @Override
    public void add(ProgramState ps) {
        this.programStates.add(ps);
    }

    @Override
    public ProgramState getCurrentPs() {
        return this.programStates.get(this.currentPsIndex);
    }
}
