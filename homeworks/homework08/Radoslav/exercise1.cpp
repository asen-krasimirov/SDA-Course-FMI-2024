#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long _x,_y;
struct Location{
    long x;
    long y;
    bool operator<(const Location& other) const {
        double deltaXThis=this->x-_x;
        double deltaYThis=this->y-_y;
        double deltaXOther=other.x-_x;
        double deltaYOther=other.y-_y;
        double distanceThis=sqrt(deltaXThis*deltaXThis+deltaYThis*deltaYThis);
        double distanceOther=sqrt(deltaXOther*deltaXOther+deltaYOther*deltaYOther);
        if (distanceThis == distanceOther) {
            if (this->x == other.x) {
                return this->y > other.y;
            }
            return this->x > other.x;
        }
        return distanceThis>distanceOther;
    }
};

int main() {
    long n,k;
    cin>>_x>>_y>>n>>k;
    priority_queue<Location> pq;
    for(int i=0;i<n;i++){
        long l,r;
        cin>>l>>r;
        Location temp{l,r};
        pq.push(temp);
    }
    for(int i=0;i<k;i++){
        Location temp=pq.top();
        cout<<temp.x<<' '<<temp.y<<'\n';
        pq.pop();
    }
    return 0;
}
