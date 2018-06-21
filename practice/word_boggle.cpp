#include <bits/stdc++.h>
using namespace std;
#define mapDeclaration map <char, vector <pair <int, int> > >

vector <pair <int, int > > getFirstChar(mapDeclaration map_chars, char c){
	vector <pair <int, int> > v;
	mapDeclaration ::iterator it;
	for (it=map_chars.begin();it!=map_chars.end();++it){
		if (it->first == c){
			v = it->second;
			break;
		}
	}
	return v;
}

int move_x[] ={-1,-1,-1,0,0,1,1,1};
int move_y[] ={-1,0,1,-1,1,-1,0,1};

bool isSafe(int x, int y, int n, int m){
	return (x>=0 && y>=0 && x<n && y<m);
}

bool foundString(int x, int y,int pos, string s,char arr[8][8], int n, int m, bool visited[8][8]){
	if (pos==s.length()){
		return true;
	}
	for (int i=0;i<8;i++){
		int new_x = x+move_x[i];
		int new_y = y+move_y[i];
		if (isSafe(new_x, new_y, n,m) && s[pos]==arr[new_x][new_y] && !visited[new_x][new_y]){
			visited[new_x][new_y] = true;
			return foundString(new_x, new_y, pos+1,s, arr,n,m,visited);
		}	
	}
	return false;
}

bool solveUtil(string s, char arr[8][8], mapDeclaration map_chars,int n, int m){
	vector <pair <int, int> > v = getFirstChar(map_chars, s[0]);
	if (v.empty()) return false;

	for (int i=0;i<v.size();i++){
		bool visited[8][8];
		memset(visited, false, sizeof(visited[0][0]));
		visited[v[i].first][v[i].second] = true;
		if (foundString(v[i].first, v[i].second,1, s,arr,n,m,visited)) return true;
	}
	return false;
}

void solve(vector <string> v, char arr[8][8], mapDeclaration map_chars,int n, int m){
	for (int i=0;i<v.size();i++){
		if (solveUtil(v[i],arr,map_chars,n,m)){
			cout<<v[i]<<" ";
		}
	}
	cout<<endl;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;		
	while (t--){
		int n,m, no_of_strings;
		cin>>no_of_strings;
		string s;
		vector <string> v;
		for (int i=0;i<no_of_strings;i++){
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		cin>>n>>m;
		map <char, vector <pair <int, int> > > map_chars;
		map <char, vector <pair <int, int> > > :: iterator it;
		char arr[8][8];
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin>>arr[i][j];
				pair <int, int> p  =make_pair(i,j);
				map_chars[arr[i][j]].push_back(p);
			}
		}		
		solve(v,arr,map_chars,n,m);
	}
	return 0;
}