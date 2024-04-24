#include <iostream>
using namespace std;

struct Team {
    string name;
    int points;
    Team* link;
};

void display(Team* first) {
    Team* current = first;

    while (current != nullptr) {
        std::cout << "Team name: " << current->name << ", ";
        cout << "team points: " << current->points << endl;
        current = current->link;
        if (current == first) {
            break;
        }
    }
    cout << endl;
}


void addTeam(Team*& first) {
    srand((unsigned)time(NULL));

    if (first != nullptr) {
        Team* current = first;

        while (current->link != first) {
            current = current->link;
        }

        Team* newTeam = new Team();
        cout << "Enter team name: ";
        cin >> newTeam->name;
        newTeam->points = rand() % 25;
        newTeam->link = first;
        current->link = newTeam;
    }
    else {
        first = new Team();
        cout << "Enter team name: ";
        cin >> first->name;
        first->points = rand() % 25;
        first->link = first;
    }
}

void DeleteTeam(Team*& head) {
    Team* current = head;
    Team* next = nullptr;

    while (current != nullptr) {
        if (current -> points <= 10){
            Team* temp = current;
            current = current->link;
            delete temp;
        }
    }
    head = nullptr;
}


int calcstages(int x, int count) {
    if (x <= 1) {
        return count;
    }
    count++;
    return calcstages(x / 2, count);
}

int countTeams(Team* first) {
    int count = 0;
    Team* current = first;
    do {
        count++;
        current = current->link;
    } while (current != first);
    return count;
}

void tournament(Team*& team_list) {
    int stages = calcstages(countTeams(team_list), 0);
    for (int i = 1; i <= stages; i++) {
        cout << "Stage " << i << ":" << endl;
        cout << "Teams before stage:" << endl;
        display(team_list);
        DeleteTeam(team_list);
        cout << "Teams after stage:" << endl;
        display(team_list);
    }
}

int main() {
    Team* team_list = nullptr;
    int x;
    cout << "How many teams should be in your tournament?: ";
    cin >> x;

    try {
        if (x % 2 != 0) {
            throw x;
        }
        for (int i = 0; i < x; i++) {
            addTeam(team_list);
        }

        cout << "Tournament teams: " << endl;
        display(team_list);

        tournament(team_list);

        
        Team* current = team_list;
        while (current != nullptr) {
            Team* temp = current;
            current = current->link;
            delete temp;
        }
    }
    catch (int) {
        cout << "Error: number of teams should be an even number";
    }

    return 0;
}