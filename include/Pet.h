#ifndef PET_SIM_PET_H
#define PET_SIM_PET_H
#include <concepts>

template <class T>
concept Pet = requires(T& t)
{
    { t.eat() } -> std::same_as<bool>;
    { t.sleep() } -> std::same_as<bool>;
    { t.play() } -> std::same_as<bool>;
    { t.die() } -> std::same_as<bool>;
};

#endif //PET_SIM_PET_H
