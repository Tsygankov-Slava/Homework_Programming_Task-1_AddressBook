#pragma once

#include <forward_list>
#include <iostream>
#include <vector>

#include "Employee/Employee.hpp"

class AddressBook {
private:
    std::forward_list<Employee> employees;

public:
    void clear();
    bool del(uint32_t id);
    void add(const Employee &employee);
    [[nodiscard]] Employee find(uint32_t id) const;
    [[nodiscard]] std::vector<Employee> getEmployers() const;
    [[nodiscard]] std::vector<Employee> find(const std::string &name) const;
    static void print(const std::vector<Employee> &employeesInAddressBook, bool inLineOutput = true, bool id = true, bool name = true, bool grade = true);
};
