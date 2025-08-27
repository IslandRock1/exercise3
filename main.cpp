/**
 * AIS2203 - Exercise 3
 * Example code to parse an XML file and print its contents using pugixml and fmt libraries.
 * Make sure to make the necessary libraries available!.
 */

#include <filesystem>

#include <pugixml.hpp>
#include <fmt/core.h>

struct Person
{
    std::string firstName;
    std::string lastName;
};

Person parsePerson(const std::filesystem::path& path) {
    pugi::xml_document doc;
    if (!doc.load_file(path.c_str())) {
        throw std::runtime_error("Failed to load XML file.");
    }

    pugi::xml_node personNode = doc.child("Person");

    Person person;
    person.firstName = personNode.child_value("FirstName");
    person.lastName = personNode.child_value("LastName");

    return person;
}

void printPerson(const Person& p)
{
    fmt::print("Person:\n  First Name: {}\n  Last Name: {}\n", p.firstName, p.lastName);
}


int main() {
    Person p = parsePerson(std::string(DATA_DIR) + "/person.xml");
    printPerson(p);

    return 0;
}
