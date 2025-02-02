class Team {
private:
    int teamNumber;
    char teamName[MAX_NAME_LENGTH];
    Player players[MAX_PLAYERS];
    int playerCount;
    int gamesPlayed;
    int wins;
    int draws;
    int losses;
    int goalsFor;
    int goalsAgainst;
    int points;
    char lastFiveResults[5];

public:
    Team();
    void setTeamNumber(int number);
    void setTeamName(const char* name);
    bool addPlayer(const Player& player);
    void updateTeamStatistics(int gf, int ga, char result);
    void displayTeamInfo() const;
};