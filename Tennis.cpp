#include <string>
#include <iostream>
using namespace std;

const string scoreNames[] = {"Love", "Fifteen", "Thirty", "Forty"};
const string tennis_score(int p1Score, int p2Score) {
   
    if (p1Score == p2Score) {
        switch (p1Score) {
            case 0: return "Love-All";
            case 1: return "Fifteen-All";
            case 2: return "Thirty-All";
            default: return "Deuce";
        }
    }

    if (p1Score >= 4 || p2Score >= 4) {
        cout<<"p1Score: "<<p1Score<<" p2Score: "<<p2Score<<endl;
        int diff = p1Score - p2Score;
        if (diff == 1) return "Advantage player 1";
        if (diff == -1) return "Advantage player 2";
        return diff >= 2 ? "Win for player 1" : "Win for player 2";
    }

    return std::string(scoreNames[p1Score]) + "-" + scoreNames[p2Score];
}

int main() {
    cout<<tennis_score(1, 0)<<endl;
    cout<<tennis_score(0, 0)<<endl;
    cout<<tennis_score(4, 0)<<endl;
    cout<<tennis_score(0, 3)<<endl;
    cout<<tennis_score(3, 4)<<endl;
    return 0;
}
