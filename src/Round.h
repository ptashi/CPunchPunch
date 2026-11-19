#ifndef ROUND_H
#define ROUND_H

#include <array>

class Round
{
public:
    static constexpr int MaxHealth = 100;

    struct Fighter
    {
        int health = MaxHealth;
        int score = 0;
        int combo = 0;
        float comboTimeLeft = 0.0f;
    };

    // Advance while the fight is active. Reinitialize with Round{} for a new round.
    void Tick(float elapsed);
    // Supply confirmed damage dealt by each fighter during the current frame.
    void ApplyHits(const std::array<int, 2>& damageDealt);

    const Fighter& GetFighter(int player) const { return fighters[player]; }
    float TimeLeft() const { return timeLeft; }
    bool TimeExpired() const { return timeLeft <= 0.0f; }

private:
    std::array<Fighter, 2> fighters{};
    float timeLeft = 99.0f;
};

#endif
