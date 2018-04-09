//
// Created by sysadmin on 25.03.2018.
//

#include <cassert>
#include "RunTests.h"

void RunTests::testDynamicVector() {
    auto vector = DynamicVector<Axolotl>(1);
    assert(vector.getCapacity() == 1);
    assert(vector.getSize() == 0);
    Axolotl testAxolotl = Axolotl(Axolotl::BREED_0, "TestName", 15, "TestPhoto");
    vector.add(testAxolotl);
    assert(vector[0].getName() == "TestName");
    vector.add(Axolotl(Axolotl::BREED_0, "TestName2", 15, "TestPhoto2"));
    assert(vector.getSize() == 2);
    assert(vector.getCapacity() == 2);
    vector.deleteElement(0);
    assert(vector.getSize() == 1);
    vector.add(Axolotl(Axolotl::BREED_0, "TestName3", 15, "TestPhoto3"));
    vector[1] = testAxolotl;
    assert(vector[1].getName() == "TestName");
}

void RunTests::testController() {
    auto controller = Controller();
    assert(controller.getVector().getCapacity() == 10);
    assert(controller.addAxolotl(controller.getVector(), 1, "TestName", 15, "TestPhoto") == true);
    assert(controller.searchAxolotl("TestName") == 10);
    assert(controller.searchAxolotl("NotInVector") == -1);
    assert(controller.updateAxolotl(0, 1, "UpdatedName", 15, "TestPhoto") == true);
    assert(controller.getVector()[0].getName() == "UpdatedName");
    controller.deleteAxolotl(0);
    assert(controller.getVector().getSize() == 10);
    assert(controller.buildFilteredVector(1, 20).getSize() == 5);
    assert(controller.getUserAdoptionVector().getSize() == 0);
}

void RunTests::testAxolotl() {
    auto axolotl = Axolotl(Axolotl::BREED_0, "TestName", 15,"TestPhoto");
    axolotl.setBreed(Axolotl::BREED_0);
    assert(axolotl.getBreed() == Axolotl::BREED_0);
    axolotl.setName("TestName");
    assert(axolotl.getName() == "TestName");
    axolotl.setAge(15);
    assert(axolotl.getAge() == 15);
    assert(axolotl.getBreedFromInt(1) == Axolotl::BREED_1);
    axolotl.setPhoto("TestPhoto");
    assert(axolotl.getPhoto() == "TestPhoto");
    assert(axolotl.getStringFromBreed(Axolotl::BREED_0) == "Breed 0");
    assert(Axolotl::getIntFromBreed(Axolotl::BREED_0) == 0);

}

void RunTests::runTests() {
    RunTests::testDynamicVector();
    RunTests::testController();
    RunTests::testAxolotl();
}
