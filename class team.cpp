
Team::Team() : teamNumber(0), playerCount(0), gamesPlayed(0), wins(0), draws(0), losses(0), goalsFor(0), goalsAgainst(0), points(0) {
    teamName[0] = '\0';
    for (int i = 0; i < 5; i++) {
        lastFiveResults[i] = '-';
    }
}

void Team::setTeamNumber(int number) {
    teamNumber = number;
}

void Team::setTeamName(const char* name) {
    int i = 0;
    while (name[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
        teamName[i] = name[i];
        i++;
    }
    teamName[i] = '\0';
}

bool Team::addPlayer(const Player& player) {
    if (playerCount < TEAM_MAX_PLAYERS) {
        players[playerCount++] = player;
        return true;
    }
    cout << "Error: Cannot add more players to the team.\n";
    return false;
}

void Team::updateTeamStatistics(int gf, int ga, char result) {
    gamesPlayed++;
    goalsFor += gf;
    goalsAgainst += ga;

    for (int i = 4; i > 0; i--) {
        lastFiveResults[i] = lastFiveResults[i - 1];
    }
    lastFiveResults[0] = result;

    if (result == 'W') {
        wins++;
        points += 3;
    } else if (result == 'D') {
        draws++;
        points += 1;
    } else if (result == 'L') {
        losses++;
    }
}

void Team::displayTeamInfo() const {
    cout << "Team Name: " << teamName << ", Games Played: " << gamesPlayed << ", Points: " << points << endl;
    cout << "Last 5 Results: ";
    for (int i = 0; i < 5; i++) {
        cout << lastFiveResults[i] << " ";
    }
    cout << endl;
}
