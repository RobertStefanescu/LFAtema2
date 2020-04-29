#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int N=109;
int n, m;
vector<int> nt[N][N], nt1[N][N];
set<int> closure[N];

void print() {
    for(int i=0; i<n; i++) {
        cout << "Q" << i << "\t";
        for(int j=1; j<=m; j++) {
            cout << "{";
            for(int ii: nt1[i][j]) cout << ii << " ";
            cout << "}\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=m; j++) {
            int temp; cin >> temp;
            nt[i][j].resize(temp);
            for(int k=0; k<nt[i][j].size(); k++) {
                cin >> nt[i][j][k];
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(i); vis[i] = 1;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            for(int k=0; k<nt[top][0].size(); k++) {
                int cur = nt[top][0][k];
                if(vis[cur] == 0) {
                    vis[cur] = 1;
                    q.push(cur);
                }
            }
        }
        for(int j=0; j<n; j++) {
            if(vis[j] == 1) closure[i].insert(j);
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int ii: closure[i]) {
            for(int j=1; j<=m; j++) {
                for(int k=0; k<nt[ii][j].size(); k++) {
                    int cur = nt[ii][j][k];
                    for(int iii: closure[cur]) {
                        nt1[i][j].push_back(iii);
                    }
                }
            }
        }
    }
    
    print();
    
    return 0;
}

