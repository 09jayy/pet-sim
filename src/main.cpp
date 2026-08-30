#include <iostream>
#include <unordered_map>
#include <functional>
#include <variant>
#include "Cat.h"
#include "Dog.h"

int main() {
    std::string action;
    std::variant<Cat, Dog> pet;
    bool game = true;

    std::unordered_map<std::string, std::function<bool()>> actions = {
        {"eat", [&pet] { return std::visit([](auto& p) { return p.eat(); }, pet); }},
        {"sleep", [&pet] { return std::visit([](auto& p) { return p.sleep(); }, pet); }},
        {"play", [&pet] { return std::visit([](auto& p) { return p.play(); }, pet); }},
        {"die", [&pet] { return std::visit([](auto& p) { return p.die(); }, pet); }}
    };

    std::cout << "Hello from pet-sim!" << std::endl;
    while (game) {
        std::cout << "What do you want to do?" << "\n";
        std::cin >> action;

        game = actions[action]();

        std::cout << game << "\n";
        std::visit([](auto& p) { std::cout << p << "\n"; }, pet);
    }

    return 0;
}
