package Repository;

import Model.GenericObject;

import java.util.ArrayList;
import java.util.List;

public class Repository {
    private List<GenericObject> repoLst;

    public Repository() {
        this.repoLst = new ArrayList<GenericObject>();
    }

    public void add(GenericObject obj) {
        this.repoLst.add(obj);
    }

    public void delete(int index) {
        this.repoLst.remove(index);
    }

    public int size() {
        return this.repoLst.size();
    }

    public List<GenericObject> getList() {
        return this.repoLst;
    }
}
