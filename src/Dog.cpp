#include "Dog.h"

bool Dog::is_alive() const {
    return hunger != 0 || wake != 0 || happy != 0 || hunger < 20 || wake < 20 || happy < 20;
}

bool Dog::eat() {
    hunger += 5;
    wake -= 3;
    happy += 3;
    return is_alive();
}

bool Dog::sleep() {
    hunger -= 3;
    wake -= 6;
    happy -= 1;
    return is_alive();
}

bool Dog::play() {
    hunger -= 5;
    wake -= 5;
    happy += 7;
    return is_alive();
}

bool Dog::die() {
    hunger = 0;
    wake = 0;
    happy = 0;
    return is_alive();
}