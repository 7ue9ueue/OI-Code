#include <iostream>
#include <fstream>
using namespace std;
 
// Returns size of largest gap between two 1s and also the index where it starts
int find_largest_interior_gap(string s, int &gap_start)
{
  int biggest_gap = 0, current_start = -1, N = s.length();
  for (int i=0; i<N; i++) 
    if (s[i] == '1') {
      if (current_start!=-1 && i-current_start > biggest_gap) {
	biggest_gap = i-current_start;
	gap_start = current_start;
      }
      current_start = i;
    }
  return biggest_gap;
}
 
// Returns size of smallest gap between two 1s
int find_smallest_interior_gap(string s)
{
  int smallest_gap = 1000000000, current_start = -1, N = s.length();
  for (int i=0; i<N; i++) 
    if (s[i] == '1') {
      if (current_start!=-1 && i-current_start < smallest_gap) smallest_gap = i-current_start;
      current_start = i;
    }
  return smallest_gap;
}
 
int try_cow_in_largest_gap(string s)
{
  int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
  if (largest_gap >= 2) {
    s[gap_start + largest_gap / 2] = '1';
    return find_smallest_interior_gap(s);
  } 
  return -1; // no gap!
}

string s;
int N;
void solve (int id)
{
    string inp = "distance"+to_string(id)+".in";
    string out = "distance"+to_string(id)+".out";
    ifstream fin (inp);
    ofstream fout (out);
    fin >> N >> s;  
 
  // Possibility 1. put two cows in largest interior gap
  int gap_start = 0;
  int largest_gap = find_largest_interior_gap(s, gap_start);
  cerr<<inp<<endl;
  cerr<<largest_gap<<N<<endl;
  fout<<largest_gap<<endl;
}


signed main () {
    for (int i=1;i<=20;i++) solve(i);
}