#include "23i-0001_Q1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); 

  
    Player player1, player2, player3;
    player1.setName("Player One");
    player1.setAge(22);
    player1.setPosition("Striker");
    player1.updateStatistics(10, 8, 3, 5, 2, 9.5);

    player2.setName("Player Two");
    player2.setAge(25);
    player2.setPosition("Midfielder");
    player2.updateStatistics(12, 5, 7, 4, 6, 8.7);

    player3.setName("Player Three");
    player3.setAge(30);
    player3.setPosition("Goalkeeper");
    player3.updateStatistics(15, 0, 1, 10, 12, 7.3);

    cout << "Player Information:\n";
    player1.getPlayerInfo();
    player2.getPlayerInfo();
    player3.getPlayerInfo();
    cout << endl;

    
    Team team1, team2;
    team1.setTeamNumber(1);
    team1.setTeamName("Red Warriors");
    team1.addPlayer(player1);
    team1.addPlayer(player2);

    team2.setTeamNumber(2);
    team2.setTeamName("Blue Knights");
    team2.addPlayer(player3);

    cout << "Team Information:\n";
    team1.displayTeamInfo();
    team2.displayTeamInfo();
    cout << endl;

  
    Season season;
    season.addTeam(team1);
    season.addTeam(team2);

    season.generateSchedule();
    for (int i = 0; i < 5; i++) { 
        season.simulateWeek();
    }

    cout << "Leaderboard After 5 Weeks:\n";
    season.displayLeaderboard();
    cout << endl;

   
    Award award(&season);
    award.calculateAwards();
    cout << "Awards:\n";
    award.displayAwards();

    return 0;
}