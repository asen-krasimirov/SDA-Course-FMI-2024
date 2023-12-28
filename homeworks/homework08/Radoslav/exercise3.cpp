#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Group {
    int num;
    int startTime;
    int endTime;
    bool operator<(const Group& other)const {
        if(startTime==other.startTime){
            return endTime<other.endTime;
        }
        return startTime < other.startTime;
    }
};


int main() {
 
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, c;
        cin >> n >> c; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<Group> v;
        for (int j = 0; j < n; j++) {
            int num,start,end;
            cin >> num >> start >> end;
            Group temp{ num,start,end };
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        bool flag = true;
        int val = 0;
        for(int j=0;j<n;j++){
            if(pq.empty() || v[j].startTime<pq.top().first){
                pq.push({v[j].endTime,v[j].num});
                val+=v[j].num;
                if(val>c){
                    flag=false;
                    cout<<0<<'\n';
                    break;
                }
            }
            else{
                while(!pq.empty() && pq.top().first<=v[j].startTime){
                    val-=pq.top().second;
                    pq.pop();
                }
                pq.push({v[j].endTime,v[j].num});
                val+=v[j].num;
                if(val>c){
                    flag=false;
                    cout<<0<<'\n';
                    break;
                }
            }
        }
        if(flag){
                cout<<"1\n";
        }
    }

    return 0;
}
