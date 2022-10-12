#include <iostream>
#include <algorithm>
using namespace std;
int player_skill[12], player_team[12], team_cnt[4];
int ans = -1;

void f(int player){
    if(player==12){
        int team_skill[4]={0, };
        for(int i=0; i<12; i++){
            team_skill[player_team[i]]+=player_skill[i];
        }
        int S = max(max(team_skill[0], team_skill[1]), max(team_skill[2], team_skill[3]));
        int s = min(min(team_skill[0], team_skill[1]), min(team_skill[2], team_skill[3]));
        
        if(ans==-1||S-s<ans){
            ans = S - s;
        }
        return;
    }
    for(int i=0; i<4; i++){
        if(team_cnt[i]<3){
            player_team[player]=i;
            team_cnt[i]++;
            f(player+1);
            team_cnt[i]--;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<12; i++){
        cin >> player_skill[i];
    }
    f(0);
    cout << ans;
    return 0;
}
