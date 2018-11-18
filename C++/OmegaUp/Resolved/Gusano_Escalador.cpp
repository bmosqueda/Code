#include <iostream>

using namespace std;

int parameters(int pulgadasPozo, int pulgadasSubir,int resbala){
  int res=0,tempo=0;
    while(res<pulgadasPozo){  
      res = pulgadasSubir+res;
      tempo++;
      if(res>=pulgadasPozo)
        return tempo;
      res -=resbala;
      tempo++;
    }
    return tempo;
}

int main(int argc, char const *argv[])
{
  int n,u,d;
  cin >> n >> u >> d;
  cout << parameters(n,u,d) << endl;
  return 0;
}