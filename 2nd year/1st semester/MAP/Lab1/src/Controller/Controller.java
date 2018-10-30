package Controller;

import Model.GenericObject;
import Repository.Repository;

import java.util.List;

public class Controller {
    private Repository repo;

    public Controller() {
        this.repo = new Repository();
    }

    public void add(GenericObject obj) {
        this.repo.add(obj);
    }

    public void delete(int index) {
        if (index < 0 || index >= this.repo.size())
            throw new Error("Index is out of bounds.");

        this.repo.delete(index);
    }

    public List<GenericObject> getRepoList() {
        return this.repo.getList();
    }
}
