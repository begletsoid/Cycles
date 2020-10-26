#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;
string convertInt(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}
void FindCycles(int begin, int finish, vector<string>* CYCLES, vector<bool> vertex, int nodes, vector<int> all, int prev, vector<int> cycle)
  {
    cycle.push_back(begin);
    if(begin == finish)
    {
      sort(cycle.begin(), cycle.end());
      string sortedCycle = "";
      for (vector<int>::iterator it = cycle.begin() ; it!=cycle.end() ; ++it)
      {
        string str = convertInt(*it);
        sortedCycle += str;
      }
      (*CYCLES).push_back(sortedCycle);
      return;
    }
    else
    {
      vertex[begin] = true;
      for(int i = 0; i < nodes; i++)
      {
        if((all[begin*nodes+i] == 1) && (vertex[i] == false) && (i != prev))
        {
          FindCycles( i,  finish,  CYCLES,  vertex, nodes,  all, begin, cycle);
        }

      }
      
    }
  }
int main() 
{
vector<int> Cycle;
vector<string> CYCLES;
int count = 0;
int nodes;
vector<bool> vertex;
vector<int> all;

  cout << "The number of nodes: ";

  cin >> nodes;

  cout << endl << "Insert an adjacency matrix:" << endl;
  for(int i = 0; i<nodes; i++) 
  {
    vertex.push_back(false);
  }
  for(int i = 0; i<nodes; i++)
  {
    for(int j = 0; j<nodes; j++)
    {
      int a;
      cin >> a;
      all.push_back(a);
    }
  }
for(int t = 0; t < nodes; t++)
{
     for(int k = 0; k < nodes; k++)
  {
        if(all[t*nodes+k] == 1)
      {
        FindCycles(k, t, &CYCLES, vertex, nodes, all, t, Cycle);
      }
  }
}
set<string> ans;
  for (vector<string>::iterator it = CYCLES.begin() ; it!=CYCLES.end() ; ++it)
        ans.insert(*it);
        cout << endl;
cout << "There is a " << ans.size() << " simple cycles";
}