#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int main(){
   int n = 0;
   cin >> n;
   vector<int> a(n),b(n);
   for(int i = 0;i < n;i++){
       cin >> a[i] >> b[i];
   }

   int f[6];
   memset(f,0,sizeof(f));

   bool iszero = true;
   for(int i = 0;i < n;i++){
       if(b[i] >= 5 && a[i] != 0) {
           f[b[i] - 5] += a[i] * b[i] * (b[i]-1) * (b[i]-2) * (b[i]-3) * (b[i]-4);
           iszero = false;
       }
   }

   if(iszero) cout << 0 << " " << 0;
   else{
       for(int i = 5;i >= 0;i--){
           if(f[i] != 0) cout << f[i] << " " << i << "\n";
       }
   }

   return 0;
}
