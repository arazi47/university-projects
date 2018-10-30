package View;

import java.util.Scanner;
import Controller.Controller;
import Model.Cube;
import Model.Cylinder;
import Model.GenericObject;
import Model.Sphere;

public class View {
    private Controller controller;
    private Scanner scanner;

    public View() {
        this.controller = new Controller();
        this.scanner = new Scanner(System.in);
    }

    private void addEntity() {
        System.out.println("1. Sphere");
        System.out.println("2. Cylinder");
        System.out.println("3. Cube");
        System.out.println("4. Back");


        System.out.print("> ");
        int input = Integer.valueOf(this.scanner.nextLine());

        int volume;
        if (input < 1 || input > 4) {
            System.out.println("Wrong input!");
        }
        if (input == 4) {
            return;
        } else {
            System.out.print("Input volume: ");
            volume = Integer.valueOf(this.scanner.nextLine());
        }

        if (input == 1) {
            this.controller.add(new Sphere(volume));
        } else if (input == 2) {
            this.controller.add(new Cylinder(volume));
        } else if (input == 3) {
            this.controller.add(new Cube(volume));
        }
    }

    private void deleteEntity() {
        System.out.print("Input index: ");
        int index = Integer.valueOf(this.scanner.nextLine());
        this.controller.delete(index);
    }

    private void displayEntities() {
        for (GenericObject obj : this.controller.getRepoList()) {
            if (obj.getVolume() >= 25)
                System.out.println(obj.toString());
        }
    }

    public void run() {
        boolean running = true;

        while (running) {
            System.out.println("1. Add entity");
            System.out.println("2. Delete entity");
            System.out.println("3. Display entities");
            System.out.println("4. Exit");

            System.out.print("> ");
            int input = Integer.valueOf(this.scanner.nextLine());

            if (input == 1) {
               this.addEntity();
            } else if (input == 2) {
                this.deleteEntity();
            } else if (input == 3) {
                this.displayEntities();
            } else if (input == 4) {
                running = false;
            } else {
                System.out.println("Wrong input!");
            }
        }
    }
}
