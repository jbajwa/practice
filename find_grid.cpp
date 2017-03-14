/* To build
  >g++ find_grid.cpp [-D_DEBUG]
   To test
  >./a.out < find_grid_input | diff find_grid_expected -
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;
bool FindGrid(vector<string> &A, int A_row, vector<string> &B, int B_row);
void FindEntry(vector<string> &A, int A_row, string B);
list< pair<int , int> > entry_p;
list< pair<int,int> >::iterator itr;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
           cin >> P[P_i];
        }
        // Set entry_p list with entry points
        FindEntry(G, R, P[0]);
        // Check for grid using the global entry_p map
        if(FindGrid(G, R, P, r)){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        #ifdef _DEBUG
        cout<<endl;
        #endif
        entry_p.erase(entry_p.begin(), entry_p.end());
    }
    return 0;
}
// Find entry points of the grid
// using list instead of map so that duplicate
// keys can be recorded
void FindEntry(vector<string> &A, int A_row, string B){
    int i,f;
    for( i=0; i< A_row; ++i){
        f = A[i].find(B);
        while (f != string::npos) {
            entry_p.push_back(pair<int,int>(i,f));
            f = A[i].find(B,f+1);
#ifdef _DEBUG
            cout<<"f ="<<f<<endl;
#endif
        }
    }
#ifdef _DEBUG
    cout<<"Entry points:"<<endl;
    for ( itr = entry_p.begin(); itr!= entry_p.end() ; itr++){
        cout<<"<"<<itr->first<<", "<<itr->second<<"> ";
    }
    cout<<endl;
#endif
}
// Starting from the entry point check for the grid
bool FindGrid(vector<string> &A, int A_row, vector<string> &B, int B_row){
    int i,f;
    int notfound ;
    for ( itr = entry_p.begin(); itr!= entry_p.end() ; itr++){
        notfound = 0;
        for( i = 0 ; i<B_row; ++i){
#ifdef _DEBUG
            cout<<A[i+(itr->first)]<<", "<<B[i]<<", "<<itr->second<<", "<<B[i].length()<<endl;
#endif
            // Using compare instead of find because we want to get the exact match
            // compare(starting position, number of chars to compare, "string to compare with")
            f = A[i+(itr->first)].compare((itr->second), B[i].length(), B[i]);
            if (f != 0){
                notfound = 1;
#ifdef _DEBUG
                cout <<"NOT FOUND "<<A[i+(itr->first)]<<", "<<B[i]<<", "<<itr->second<<", "<<B[i].length()<<endl;
#endif
                break;
            }
#ifdef _DEBUG
            else {
                cout <<"FOUND "<<A[i+(itr->first)]<<", "<<B[i]<<", "<<itr->second<<", "<<B[i].length()<<endl;
            }
#endif
        }
        if(!notfound) return true;
    }
    return false;
}
