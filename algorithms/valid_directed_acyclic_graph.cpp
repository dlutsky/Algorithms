#include<vector>
#include<utility>
#include<string.h>

int dfs(std::vector<int> *adj_list, int *indegree, int v){
	int count = 0;
	for(int i=0; i<adj_list[v].size(); i++){
		if(--indegree[adj_list[v][i]] == 0){
			count += dfs(adj_list, indegree, adj_list[v][i])+1;
		}
		else{
			count++;
		}
	}
	indegree[v]--;
	return count;
}

bool isDAG(int num, std::vector<std::pair<int, int>>& edges){
	std::vector<int> adj_list[num];
	int indegree[num];
	memset(indegree, 0, sizeof(indegree));
	for(int i=0; i<edges.size(); i++){
		adj_list[edges[i].first].push_back(edges[i].second);
		indegree[edges[i].second]++;
	}
	
	int count = 0;
	for(int i=0; i<num; i++){
		if(indegree[i] == 0){
			count += dfs(adj_list, indegree, i);
		}
	}
	if(count != edges.size())
		return false;
	return true;
}
