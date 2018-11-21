package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.util.List;

public interface IRepo {
    //ProgramState getCurrentPs();
    void addProgramState(ProgramState ps);

    void setProgramStatesList(List<ProgramState> psList);
    List<ProgramState> getProgramStates();

    void logPrgStateExec(ProgramState ps);
}
