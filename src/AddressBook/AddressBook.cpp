#include "AddressBook.hpp"

void AddressBook::add(const Employee &employee) {
    employees.push_front(employee);
}

bool AddressBook::del(const uint32_t id) {
    auto prevEmploy = employees.before_begin();
    for (auto employee = employees.begin(); employee != employees.end(); ++employee) {
        if (employee->id == id) {
            employees.erase_after(prevEmploy);
            return true;
        }
        prevEmploy = employee;
    }
    return false;
}

Employee AddressBook::find(uint32_t id) const {
    for (const auto &employee: employees) {
        if (employee.id == id) {
            return employee;
        }
    }
    return {};
}

std::vector<Employee> AddressBook::find(const std::string &name) const {
    std::vector<Employee> foundEmployees;
    for (const auto &employee: employees) {
        if (employee.name == name) {
            foundEmployees.push_back(employee);
        }
    }
    if (!foundEmployees.empty()) {
        return foundEmployees;
    }
    return {};
}

void AddressBook::clear() {
    employees.clear();
}

std::vector<Employee> AddressBook::getEmployers() const {
    std::vector<Employee> result;
    for (const auto &employee: employees) {
        result.push_back(employee);
    }
    return result;
}
void AddressBook::print(const std::vector<Employee> &employeesInAddressBook, bool inLineOutput, bool id, bool name, bool grade) {
    std::string e;
    std::cout << "The given employees: ";
    if (!inLineOutput) {
        std::cout << "\n\t";
    }
    for (const auto &employer: employeesInAddressBook) {
        e = "";
        if (id) {
            e += "id : " + std::to_string(employer.id);
        }
        if (name) {
            if (id) {
                e += ", ";
            }
            e += "name : " + employer.name;
        }
        if (grade) {
            if (name) {
                e += ", ";
            }
            e += "grade : " + std::to_string(employer.grade);
        }
        std::cout << "{" << e << "}"
                  << " -> ";
        if (!inLineOutput) {
            std::cout << "\n\t";
        }
    }
    std::cout << "count : " << employeesInAddressBook.size() << "\n\n";
}
