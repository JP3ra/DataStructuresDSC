#include <iostream>
#include <string>
using namespace std;
class PersonData {
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string phone;

public:
    PersonData(string lastName, string firstName, string address, string city, string state, string phone) {
        this->lastName = lastName;
        this->firstName = firstName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->phone = phone;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    string getLastName() {
        return this->lastName;
    }

    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    string getFirstName() {
        return this->firstName;
    }

    void setAddress(string address) {
        this->address = address;
    }

    string getAddress() {
        return this->address;
    }

    void setCity(string city) {
        this->city = city;
    }

    string getCity() {
        return this->city;
    }

    void setState(string state) {
        this->state = state;
    }

    string getState() {
        return this->state;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }

    string getPhone() {
        return this->phone;
    }
};

class CustomerData : public PersonData {
private:
    int customerNumber;
    string email;

public:
    CustomerData(string lastName, string firstName, string address, string city, string state, string phone, int customerNumber, string email) : PersonData(lastName, firstName, address, city, state, phone) {
        this->customerNumber = customerNumber;
        this->email = email;
    }

    void setCustomerNumber(int customerNumber) {
        this->customerNumber = customerNumber;
    }

    int getCustomerNumber() {
        return this->customerNumber;
    }

    void setEmail(string email) {
        this->email = email;
    }

    string getEmail() {
        return this->email;
    }
};

int main() {
    CustomerData customer("Smith", "John", "123 Main St", "Anytown", "NY", "555-555-5555", 123, "john.smith@email.com");
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << ", " << customer.getCity() << ", " << customer.getState() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Email: " << customer.getEmail() << endl;
    return 0;
}