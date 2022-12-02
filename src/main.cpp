#include "AddressBook/AddressBook.hpp"

int main() {
    AddressBook ab;

    Employee e1, e2;
//    std::cin >> e1 >> e2;
//    ab.add(e1);
//    ab.add(e2);
    ab.add({1, "Test2", 2});
    ab.add({3, "Test2", 2});
    //ab.add({4, "Test4", 1});
    std::cout << ab << "\n";
    ab += {4, "Test4", 1};
    ab = ab + Employee{5, "Test4", 1};
    std::cout << ab << "\n";
    ab -= 4;
    std::cout << ab << "\n";
    auto a = ab.find(3).value();
    ab = ab - a.id;
    std::cout << ab << "\n";
    //std::cout << ab[1] << ab["name"];
    a.name = "aaaa";
    ab.update(20, a);
    std::cout << (e1 != e2) << " " << (e1 == a) << "\n";

    AddressBook ab2;
    ab2 = ab;
    ab2.find(3).value().name = "sfg";

    ab.del(3);
    ab.del(4);
    std::cout << ab << ab2;
    std::cout << a;


    return 0;
}

// Адресная книга также должна иметь прямой доступ к редактированию полей класса Employee
// правильно копировать (конструктор и присваивание) адресную книгу
// Должна быть возможность вывести на экран адресную книгу, и отдельно Employee через оператор <<
// Возможность ввести данные для Employee через консоль >>
// Поддержка операторов сравнения для класса Employee == !=
// Взятие по индексу, в качестве аргумента должна быть поддержка и для id и для имени(брать первый элемент с таким именем) []
// Возможность добавить новый элемент в адресную книгу через оператор +
// Возможность удалить элемент (по ID) из адресной книги через оператор -


