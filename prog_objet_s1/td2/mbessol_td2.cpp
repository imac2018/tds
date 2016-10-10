//  Pas vérifier si tout marche. TD non fini.
//  main.cpp
//  TD2

//
//  Created by Matthieu Bessol on 27/09/2016.
//  Copyright © 2016 Matthieu Bessol. All rights reserved.
//

#include <iostream>

class Address {
private:
    std::string country;
    std::string city;
    unsigned int number;
    std::string street;
    std::string postalCode;
public:

    Address(std::string _country, std::string _city, unsigned int _number, std::string _street, std::string _postalCode ) {
        if(_country != "")
            this->country = _country;
        else
            std::cout << "Not a good country, can't init it.\n";

        if(_city != "")
            this->city = _city;
        else
            std::cout << "Not a good city, can't init it.\n";

        if(_number > 0)
            this->number = _number;
        else
            std::cout << "Not a good street number, can't init it.\n";

        if(_street != "")
            this->street = _street;
        else
            std::cout << "Not a good street, can't init it.\n";

        if(_postalCode != "")
            this->postalCode = _postalCode;
        else
            std::cout << "Not a good postal code, can't init it.\n";
    }

    void printAddress() {
        std::cout << country << ", " << city << ", " << number << " " << street << ", " << postalCode << std::endl;
    }
};


class Person {
private:
    std::string name;
    unsigned int age;
    unsigned int height;
    Address address = Address("","",0,"","");

public:
    Person(std::string _name, unsigned int _age, unsigned int _height, std::string _country, std::string _city, unsigned int _number, std::string _street, std::string _postalCode){
        if(_name != "")
            this->name = _name;
        else
            std::cout << "Not a good name, can't init it.\n";

        if(_age > 0 && _age < 110 )
            this->age = _age;
        else
            std::cout << "Not a good age, can't init it.\n";

        if(_height > 20 && _height < 250)
            this->height = _height;
        else
            std::cout << "Not a good height, can't change it.\n";

        this->address = Address(_country,_city,_number,_street,_postalCode);
    }

    void printAge() {
        if(age > 0 && age < 110 )
            std::cout << age << std::endl;
        else
            std::cout << "Not a good age, can't print it.\n";
    }

    void printHeight() {
        if(height > 20 && height < 250 )
            std::cout << height << std::endl;
        else
            std::cout << "Not a good height, can't print it.\n";
    }

    void prinName() {
        if(name != "")
            std::cout << name << std::endl;
        else
            std::cout << "Not a good name, can't print it.\n";
    }

    void printAddress() {
        address.printAddress();
    }

    std::string getName() {
        return name;
    }

    unsigned int getAge() {
        return age;
    }

    unsigned int getHeight() {
        return height;
    }

    void setName(std::string _name) {
        if(_name != "")
            name = _name;
        else
            std::cout << "Not a good name, can't change it.\n";

    }

    void setAge(unsigned int _age) {
        if(_age > 0 && _age < 110 )
            age = _age;
        else
            std::cout << "Not a good age, can't change it.\n";
    }

    void setHeight(unsigned int _height) {
        if(_height > 20 && _height < 250)
            height = _height;
        else
            std::cout << "Not a good height, can't change it.\n";
    }
};

int main(int argc, const char * argv[]) {
    Person Leopoldine = Person("Leopoldine", 22, 160, "France", "Héricy",16, "rue grande", "77850");
    Leopoldine.prinName();
    Leopoldine.printAge();
    Leopoldine.printHeight();
    Leopoldine.setName("Leoetlesbas");
    Leopoldine.prinName();
    Leopoldine.printAddress();

    return 0;
}
