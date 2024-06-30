#include "player.h"

Player::Player() : max_hp(100), hp(100), money(0), weapon(nullptr) {
    this->weapon = new Pistolet();
}

void Player::Shoot(Enemy* enemy) {
    int random = rand() % 100;
    int dodge = 1;
    if (random < enemy->dodge_Chance) {
        dodge = 0;
    }
    enemy->hp = enemy->hp - weapon->damage * dodge;
    weapon->Shoot();
}

void Player::Reload() {
    weapon->Reload();
}

Player::~Player() {
    delete this->weapon;
}
