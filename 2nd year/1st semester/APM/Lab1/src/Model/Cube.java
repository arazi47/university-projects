package Model;

public class Cube implements GenericObject {
    private int volume;

    public Cube(int volume) {
        this.volume = volume;
    }

    @Override
    public int getVolume() {
        return this.volume;
    }

    @Override
    public String toString() {
        return "Cube with volume " + String.valueOf(this.getVolume()) + ".";
    }
}
