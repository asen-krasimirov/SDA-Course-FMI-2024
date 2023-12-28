#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string s1,s2;
    cin >> s1 >> s2;

    long long n = s1.size();
    long long m = s2.size();
    
    long long dp_matrix[2][m+1];
    dp_matrix[0][0]=0;
    dp_matrix[1][0]=0;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<m;j++){
            dp_matrix[i][j]=0;
        }
    }
    
    long long res=0;
    
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            if(s1[i]==s2[j]){
                dp_matrix[(i+1)%2][j+1]=dp_matrix[i%2][j]+1;
                
                if(dp_matrix[i%2][j]+1>res){
                    res=dp_matrix[j%2][i]+1;
                }
            }
            else{
                 dp_matrix[(i + 1) % 2][j + 1] = 0;
            }
        }
    }
    
    cout<<res;
    return 0;
}
