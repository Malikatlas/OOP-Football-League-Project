#ifndef FANTASY_FOOTBALL_LEAGUE_H
#define FANTASY_FOOTBALL_LEAGUE_H

const int MAX_NAME_LENGTH = 50;
const int MAX_PLAYERS = 30;
const int MAX_TEAMS = 10;
const int SEASON_LENGTH = 10;
const int TEAM_MIN_PLAYERS = 11;
const int TEAM_MAX_PLAYERS = 25;


class Player {
private:
    char name[MAX_NAME_LENGTH];
    int age;
    char position[20];
    int gamesPlayed;
    int goalsScored;
    int assists;
    int tackles;
    int interceptions;
    float skillRating;

public:
    Player();
    void setName(const char* playerName);
    void setAge(int playerAge);
    void setPosition(const char* playerPosition);
    void updateStatistics(int games, int goals, int assistsMade, int tacklesMade, int interceptionsMade, float skill);
    void resetStatistics();
    void getPlayerInfo() const;
};

