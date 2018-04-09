//
// Created by sysadmin on 25.03.2018.
//

#include <cassert>
#include "RunTests.h"

void RunTests::testDynamicVector() {
    vector<Axolotl> vec;
    assert(vec.capacity() == 0);
    assert(vec.size() == 0);
    Axolotl testAxolotl = Axolotl(Axolotl::BREED_0, "TestName", 15, "TestPhoto");
    vec.push_back(testAxolotl);
    vec.emplace_back(Axolotl(Axolotl::BREED_0, "TestName2", 15, "TestPhoto2"));
    assert(vec.size() == 2);
    assert(vec.capacity() == 2);

    // Delete element found at index 0
    vec.erase(vec.begin() + 0);
    assert(vec.size() == 1);

    vec.emplace_back(Axolotl(Axolotl::BREED_0, "TestName3", 15, "TestPhoto3"));
    vec[1] = testAxolotl;
    assert(vec[1].getName() == "TestName");
}

void RunTests::testController() {
    auto controller = Controller();
    assert(controller.addAxolotl(controller.getVector(), 1, "TestName", 15, "TestPhoto"));
    assert(controller.searchAxolotl("TestName") == 10);
    assert(controller.searchAxolotl("NotInVector") == -1);
    assert(controller.updateAxolotl(0, 1, "UpdatedName", 15, "TestPhoto"));
    assert(controller.getVector()[0].getName() == "UpdatedName");
    controller.deleteAxolotl(0);
    assert(controller.getVector().size() == 10);
    assert(controller.buildFilteredVector(1, 20).size() == 5);
    assert(controller.getUserAdoptionVector().empty());
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
