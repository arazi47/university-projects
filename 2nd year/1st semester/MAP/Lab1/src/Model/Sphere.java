package Model;

public class Sphere implements GenericObject {
    private int volume;

    public Sphere(int volume) {
        this.volume = volume;
    }

    @Override
    public int getVolume() {
        return this.volume;
    }

    @Override
    public String toString() {
        return "Sphere with volume " + String.valueOf(this.getVolume()) + ".";
    }
}
