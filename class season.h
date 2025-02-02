class Season {
private:
    Team teams[MAX_TEAMS];
    int teamCount;
    int schedule[MAX_TEAMS][SEASON_LENGTH]; 
    int currentWeek;

public:
    Season();
    bool addTeam(const Team& team);
    void generateSchedule();
    void simulateWeek();
    void displayLeaderboard() const;
};