
Award::Award(Season* season) : seasonReference(season) {}

void Award::calculateAwards() {
    for (int i = 0; i < MAX_TEAMS; i++) {
        
        Team currentTeam = seasonReference->teams[i];

        Player bestPlayer;
        float bestRating = 0.0;

        for (int j = 0; j < currentTeam.playerCount; j++) {
            Player currentPlayer = currentTeam.players[j];
            if (currentPlayer.skillRating > bestRating) {
                bestRating = currentPlayer.skillRating;
                bestPlayer = currentPlayer;
            }
        }
        bestPlayers[i] = bestPlayer;
    }
}

void Award::displayAwards() const {
    cout << "Player Awards:\n";
    for (int i = 0; i < MAX_TEAMS; i++) {
        cout << "Best Player from Team " << i + 1 << ":\n";
        bestPlayers[i].getPlayerInfo();
    }
}