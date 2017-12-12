//
// Created by aymer on 12/12/2017.
//

#include "Player.h"

Player::Player() = default;

void Player::setId(char id) {
    this->m_id = id;
}

void Player::setName(std::string name) {
    this->m_name = name;
}

char Player::getId() {
    return this->m_id;
}

std::string Player::getName() {
    return this->m_name;
}