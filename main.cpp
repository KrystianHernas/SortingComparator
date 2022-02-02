#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

struct Player {
    int score;
    std::string name;
};

class Checker {
public:
    // complete this method
    static int comparator(Player a, Player b, int i) {

        if (a.name[i] > b.name[i]) return -1;
        else if (a.name[i] == b.name[i]) return comparator(a, b, i+1);
        else return 1;
    }
};

bool compare(Player a, Player b) {
    if (Checker::comparator(a, b, 0) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<Player> players;
    std::string name;
    int score;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);

    for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < players.size()-1; j++) {
            if (players[j].score < players[j + 1].score) 
                std::swap(players[j], players[j + 1]);
        }
    }
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " " << players[i].score << std::endl;
    }
    return 0;
}