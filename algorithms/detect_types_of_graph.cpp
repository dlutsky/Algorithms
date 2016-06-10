#include<vector>
#include<utility>
#include<string>
#include<string.h>

static const char* TypeStrings[] = {"tree", "forest", "bipartite", "graph"};

int dfs(std::vector<int> *adj_list, int *len, int v, int l, int p){
	int type = 0;
	len[v] = l;
	for(int i=0; i<adj_list[v].size(); i++){
		if(adj_list[v][i] == p)
			continue;
		if(len[adj_list[v][i]]){
			if(type!=3 && (l-len[adj_list[v][i]])%2)
				type = 2;
			else
				type =3;
			continue;
		}
		type = dfs(adj_list, len, adj_list[v][i], l+1, v);
	}
	return type;
}

std::string detect(int num, std::vector<std::pair<int, int>> edges){
	std::vector<int> adj_list[num];
	for(int i=0; i<edges.size(); i++){
		adj_list[edges[i].first].push_back(edges[i].second);
		adj_list[edges[i].second].push_back(edges[i].first);
	}
	int len[num];
	memset(len, 0, sizeof(len));
	int type = 0;
	int tree_count = -1;
	for(int i=0; i<num; i++){
		if(len[i])
			continue;
		tree_count++;
		type = dfs(adj_list, len, i, 0, -1);
	}
	if(type==0 && tree_count>0)
		type = 1;
	return TypeStrings[type];
}

