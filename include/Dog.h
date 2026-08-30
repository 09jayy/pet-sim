#ifndef PET_SIM_DOG_H
#define PET_SIM_DOG_H
#include "Pet.h"
#include <iostream>

class Dog {
private:
    int happy{10}, hunger{10}, wake{10};

    bool is_alive() const;
public:
    Dog() = default;
    bool eat();
    bool sleep();
    bool play();
    bool die();

    friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
        os << "Dog {\n hunger: " << dog.hunger << "\n wake: " << dog.wake << "\n happy: " << dog.happy<< "\n }";
        return os;
    }
};

static_assert(Pet<Dog>, "Dog does not satisfy Pet");

#endif //PET_SIM_DOG_H
