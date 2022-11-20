#include "gtest/gtest.h"

#include "AddressBook/AddressBook.cpp"

class AddressBookFixture : public ::testing::Test {
protected:
    AddressBook ab;
};

TEST_F(AddressBookFixture, TestAddFunction) {
    // Act
    ab.add({1, "Name1", 5});

    // Assert
    for (const auto &employee: ab.getEmployers()) {
        ASSERT_EQ(employee.id, 1);
        ASSERT_EQ(employee.name, "Name1");
        ASSERT_EQ(employee.grade, 5);
    }
}

TEST_F(AddressBookFixture, TestManyAddFunction) {
    //Average
    const std::vector<Employee> &result = {{3, "Name3", 5},
                                           {2, "Name2", 4},
                                           {1, "Name1", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    // Assert
    const auto &employers = ab.getEmployers();
    for (int i = 0; i < employers.size(); ++i) {
        ASSERT_EQ(employers[i].id, result[i].id);
        ASSERT_EQ(employers[i].name, result[i].name);
        ASSERT_EQ(employers[i].grade, result[i].grade);
    }
}

TEST_F(AddressBookFixture, TestDelFunctionExistID) {
    //Average
    const std::vector<Employee> &result = {{1, "Name1", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    bool status1 = ab.del(2);
    bool status2 = ab.del(3);

    // Assert
    ASSERT_EQ(true, status1);
    ASSERT_EQ(true, status2);

    const auto &employers = ab.getEmployers();
    for (int i = 0; i < employers.size(); ++i) {
        ASSERT_EQ(employers[i].id, result[i].id);
        ASSERT_EQ(employers[i].name, result[i].name);
        ASSERT_EQ(employers[i].grade, result[i].grade);
    }
}

TEST_F(AddressBookFixture, TestDelFunctionNotExistID) {
    // Act
    ab.add({1, "Name1", 5});

    bool status = ab.del(2);

    // Assert
    ASSERT_EQ(false, status);
}

TEST_F(AddressBookFixture, TestFindFunctionExistID) {
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(2);

    // Assert
    ASSERT_EQ(employee.id, result.id);
    ASSERT_EQ(employee.name, result.name);
    ASSERT_EQ(employee.grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistID) {
    //Average
    const Employee &result = {};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(4);

    // Assert
    ASSERT_EQ(employee.id, result.id);
    ASSERT_EQ(employee.name, result.name);
    ASSERT_EQ(employee.grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionExistName) {
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name2");

    // Assert
    ASSERT_EQ(employee[0].id, result.id);
    ASSERT_EQ(employee[0].name, result.name);
    ASSERT_EQ(employee[0].grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistName) {
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name4");

    // Assert
    ASSERT_TRUE(employee.empty());
}

TEST_F(AddressBookFixture, TestFindFunctionManyExistName) {
    //Average
    const std::vector<Employee> &result = {{3, "Name2", 5},
                                           {2, "Name2", 4}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name2", 5});

    const auto &employers = ab.find("Name2");

    // Assert
    for (int i = 0; i < employers.size(); ++i) {
        ASSERT_EQ(employers[i].id, result[i].id);
        ASSERT_EQ(employers[i].name, result[i].name);
        ASSERT_EQ(employers[i].grade, result[i].grade);
    }
}

TEST_F(AddressBookFixture, TestClearFunction) {
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    ab.clear();

    // Assert
    ASSERT_TRUE(ab.getEmployers().empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}