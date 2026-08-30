#include <iostream>
#include <unordered_map>
#include <functional>
#include <variant>
#include "Cat.h"
#include "Dog.h"
#include "Actions.h"

int main() {
    std::string userAction;
    std::variant<Cat, Dog> pet;
    bool game = true;

    std::unordered_map<Actions, std::function<bool()>> actions = {
        {Actions::Eat, [&pet] {
            return std::visit([](auto& p) { return p.eat(); }, pet);
        }},
        {Actions::Sleep, [&pet] {
            return std::visit([](auto& p) { return p.sleep(); }, pet);
        }},
        {Actions::Play, [&pet] {
            return std::visit([](auto& p) { return p.play(); }, pet);
        }},
        {Actions::Die, [&pet] {
            return std::visit([](auto& p) { return p.die(); }, pet);
        }},
        {Actions::Unknown, [] {
            std::cout << "invalid" << "\n"; return true;
        }}
    };

    std::cout << "Hello from pet-sim!" << std::endl;
    while (game) {
        std::cout << "What do you want to do?" << "\n";
        std::cin >> userAction;

        game = actions[action(userAction)]();

        std::visit([](auto& p) { std::cout << p << "\n"; }, pet);
    }
    std::cout << "GAME OVER";
}
