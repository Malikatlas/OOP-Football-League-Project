
Season::Season() : teamCount(0), currentWeek(0) {
    for (int i = 0; i < MAX_TEAMS; i++) {
        for (int j = 0; j < SEASON_LENGTH; j++) {
            schedule[i][j] = -1; // Initialize schedule with -1 (no match)
        }
    }
}

bool Season::addTeam(const Team& team) {
    if (teamCount < MAX_TEAMS) {
        teams[teamCount++] = team;
        return true;
    }
    cout << "Error: Cannot add more teams to the season.\n";
    return false;
}

void Season::generateSchedule() {
    // Simple round-robin schedule generation
    for (int i = 0; i < teamCount; i++) {
        for (int j = i + 1; j < teamCount; j++) {
            if (currentWeek < SEASON_LENGTH) {
                schedule[i][currentWeek] = j;
                schedule[j][currentWeek] = i;
                currentWeek++;
            }
        }
    }
    currentWeek = 0; // Reset to start scheduling from Week 1
}

void Season::simulateWeek() {
    if (currentWeek >= SEASON_LENGTH) {
        cout << "Season has ended. No more weeks to simulate.\n";
        return;
    }

    cout << "Simulating Week " << currentWeek + 1 << "...\n";
    for (int i = 0; i < teamCount; i++) {
        if (schedule[i][currentWeek] != -1) {
            int opponentIndex = schedule[i][currentWeek];
            if (i < opponentIndex) { 
                // Generate random game stats
                int goalsForTeam1 = rand() % 5;
                int goalsForTeam2 = rand() % 5;

                char resultTeam1, resultTeam2;
                if (goalsForTeam1 > goalsForTeam2) {
                    resultTeam1 = 'W';
                    resultTeam2 = 'L';
                } else if (goalsForTeam1 < goalsForTeam2) {
                    resultTeam1 = 'L';
                    resultTeam2 = 'W';
                } else {
                    resultTeam1 = resultTeam2 = 'D';
                }

                teams[i].updateTeamStatistics(goalsForTeam1, goalsForTeam2, resultTeam1);
                teams[opponentIndex].updateTeamStatistics(goalsForTeam2, goalsForTeam1, resultTeam2);
            }
        }
    }
    currentWeek++;
}

void Season::displayLeaderboard() const {
    // Sort teams by points, goal difference, and goals scored
    Team sortedTeams[MAX_TEAMS];
    for (int i = 0; i < teamCount; i++) {
        sortedTeams[i] = teams[i];
    }

    // Bubble sort to rank teams
    for (int i = 0; i < teamCount - 1; i++) {
        for (int j = 0; j < teamCount - i - 1; j++) {
            if (sortedTeams[j].points < sortedTeams[j + 1].points) {
                Team temp = sortedTeams[j];
                sortedTeams[j] = sortedTeams[j + 1];
                sortedTeams[j + 1] = temp;
            }
        }
    }

    cout << "Leaderboard:\n";
    for (int i = 0; i < teamCount; i++) {
        cout << i + 1 << ". ";
        sortedTeams[i].displayTeamInfo();
    }
}