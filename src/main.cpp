#include "AddressBook/AddressBook.hpp"

int main() {
    AddressBook ab;

    ab.add({1, "Test1", 5});
    ab.add({2, "Test2", 3});
    ab.add({3, "Test2", 2});
    ab.add({4, "Test4", 1});
    AddressBook::print(ab.getEmployers());

    ab.del(3);
    ab.del(4);
    AddressBook::print(ab.getEmployers(), false);

    auto a = ab.find(1);
    AddressBook::print({a});

    auto b = ab.find("Test2");
    AddressBook::print(b);

    return 0;
}
