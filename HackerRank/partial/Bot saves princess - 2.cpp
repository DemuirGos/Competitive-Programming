#include <iostream>
#include <vector>
using namespace std;
class point{
   public:
    int x;
    int y;
};
void nextMove(int n, int r, int c, vector <string> grid){
    point loc_p,loc_m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(grid[i][j]=='p'){
                loc_p.x=j;loc_p.y=i;
                break;
            }
        }
    loc_m.x=c;loc_m.y=r;
    int ver=loc_m.x-loc_p.x;
    int hor=loc_m.y-loc_p.y;
    int h_l,v_l;v_l=ver>0?ver:-ver;h_l=hor>0?hor:-hor;
    for(;v_l>0 || h_l>0;){
        if(v_l--){
            if(ver>0) cout << "LEFT\n";
            else if(ver<0) cout << "RIGHT\n";
            return;
        }
        if(h_l--){
            if(hor<0) cout << "DOWN\n";
            else if(hor>0) cout << "UP\n";
            return;
        }
    }
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}