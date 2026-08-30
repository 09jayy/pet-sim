#ifndef PET_SIM_ACTIONS_H
#define PET_SIM_ACTIONS_H
#include <array>
#include <string>

enum class Actions {
    Eat,
    Sleep,
    Play,
    Die,
    Unknown
};

inline Actions action(std::string_view str) {
    constexpr std::array mappings = {
        std::pair{"eat", Actions::Eat },
        std::pair{"sleep", Actions::Sleep },
        std::pair{"play", Actions::Play },
        std::pair{ "die", Actions::Die},
    };
    for (const auto& [name, action] : mappings) {
        if (name == str) return action;
    }
    return Actions::Unknown;
}

#endif //PET_SIM_ACTIONS_H
