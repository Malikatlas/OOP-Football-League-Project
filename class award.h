class Award {
private:
    Season* seasonReference;
    Player bestPlayers[MAX_TEAMS];

public:
    Award(Season* season);
    void calculateAwards();
    void displayAwards() const;
};

#endif