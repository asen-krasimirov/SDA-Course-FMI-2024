#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int count = 0;
    size_t pos = s2.find(s1);
    
    while(pos!=string::npos){
        count++;
        pos = s2.find(s1,pos+1);
    }
    
    std::cout << count;
    return 0;
}
