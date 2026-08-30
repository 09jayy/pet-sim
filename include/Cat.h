#ifndef PET_SIM_CAT_H
#define PET_SIM_CAT_H
#include "Pet.h"
#include <iostream>

class Cat {
private:
    int happy, hunger, wake;

    bool is_alive() const;
public:
    Cat() = default;
    bool eat();
    bool sleep();
    bool play();
    bool die();

    friend std::ostream& operator<<(std::ostream& os, const Cat& cat) {
        os << "Cat {\n hunger: " << cat.hunger << "\n wake: " << cat.wake << "\n happy: " << cat.happy << "\n }";
        return os;
    }
};

static_assert(Pet<Cat>, "Cat does not satisfy Pet");

#endif //PET_SIM_CAT_H
