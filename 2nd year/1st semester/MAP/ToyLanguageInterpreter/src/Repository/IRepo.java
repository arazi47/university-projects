package Repository;

import Model.ProgramState;

public interface IRepo {
    ProgramState getCurrentPs();
    void add(ProgramState ps);

    void logPrgStateExec();
}
