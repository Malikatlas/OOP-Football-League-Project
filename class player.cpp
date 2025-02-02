#include "23i-0001_Q1.h"
#include <iostream>
using namespace std;


Player::Player() : age(0), gamesPlayed(0), goalsScored(0), assists(0), tackles(0), interceptions(0), skillRating(0.0) {
    name[0] = '\0';
    position[0] = '\0';
}

void Player::setName(const char* playerName) {
    int i = 0;
    while (playerName[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
        name[i] = playerName[i];
        i++;
    }
    name[i] = '\0';
}

void Player::setAge(int playerAge) {
    if (playerAge >= 18) {
        age = playerAge;
    } else {
        cout << "Error: Player age must be 18 or higher.\n";
    }
}

void Player::setPosition(const char* playerPosition) {
    int i = 0;
    while (playerPosition[i] != '\0' && i < 19) {
        position[i] = playerPosition[i];
        i++;
    }
    position[i] = '\0';
}

void Player::updateStatistics(int games, int goals, int assistsMade, int tacklesMade, int interceptionsMade, float skill) {
    gamesPlayed += games;
    goalsScored += goals;
    assists += assistsMade;
    tackles += tacklesMade;
    interceptions += interceptionsMade;
    skillRating = skill;
}

void Player::resetStatistics() {
    gamesPlayed = goalsScored = assists = tackles = interceptions = 0;
    skillRating = 0.0;
}

void Player::getPlayerInfo() const {
    cout << "Name: " << name << ", Age: " << age << ", Position: " << position << endl;
    cout << "Stats -> Games: " << gamesPlayed << ", Goals: " << goalsScored
         << ", Assists: " << assists << ", Tackles: " << tackles
         << ", Interceptions: " << interceptions << ", Skill: " << skillRating << endl;
}

