#include "player.h"

Player::Player() : hp(100), money(0), weapon(nullptr) {
    this->weapon = new Machinegun();
}

void Player::Shoot() {
    if (weapon->ammo != 0) {
        money++;
    }
    weapon->Shoot();
}

void Player::Reload() {
    weapon->Reload();
}

Player::~Player() {
    delete this->weapon;
}
