#include "Round.h"

#include <algorithm>

namespace
{
constexpr float ComboWindow = 1.25f;
}

void Round::Tick(float elapsed)
{
    elapsed = std::max(0.0f, elapsed);
    timeLeft = std::max(0.0f, timeLeft - elapsed);
    for (auto& fighter : fighters)
    {
        fighter.comboTimeLeft = std::max(0.0f, fighter.comboTimeLeft - elapsed);
        if (fighter.comboTimeLeft <= 0.0f)
            fighter.combo = 0;
    }
}

void Round::ApplyHits(const std::array<int, 2>& damageDealt)
{
    for (int player = 0; player < 2; ++player)
    {
        auto& attacker = fighters[player];
        auto& defender = fighters[1 - player];
        const int damage = std::clamp(damageDealt[player], 0, defender.health);
        if (damage == 0)
            continue;

        defender.health -= damage;
        ++attacker.combo;
        attacker.comboTimeLeft = ComboWindow;
        attacker.score += damage * attacker.combo;
    }
}
