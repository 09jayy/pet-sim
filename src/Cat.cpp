#include "Cat.h"

bool Cat::is_alive() const {
    return hunger > 0 && wake > 0 && happy > 0;
}

bool Cat::eat() {
    hunger += 5;
    wake -= 3;
    happy += 3;
    return is_alive();
}

bool Cat::sleep() {
    hunger -= 3;
    wake -= 6;
    happy -= 1;
    return is_alive();
}

bool Cat::play() {
    hunger -= 5;
    wake -= 5;
    happy += 7;
    return is_alive();
}

bool Cat::die() {
    hunger = 0;
    wake = 0;
    happy = 0;
    return is_alive();
}
