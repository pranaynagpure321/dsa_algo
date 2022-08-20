/* this question is about finding isolated graphs and then take the ceil(sqrt(TotalCntofNodes)

emaplse if we have 5 nodes in grah and 2 other isolated nodes then then ceil(sqrt(5)) + ceil(sqrt(1)) + ceil(sqrt(1)) = 5 

basically we need to fibnd the isolaed parts of graphs in given scenario

input
n = 10
edges = [1,1,4,5,6]
edges2 = [2,3,2,3,7]

ans = 5

*/


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> adj;


void addEdge(int u , int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int dfs(vector<vector<int>> &adj , vector<int> & visi,int start )
{
    if(visi[start]) return 1;
    
    visi[start]= true;
    vector<int> t = adj[start];
    int count =0;
    for(int i =0 ;i< t.size() ;i++)
    {
        int nextNode =t[i];
        
        if(!visi[nextNode])
        {
            count  += 1 + dfs(  adj,  visi,nextNode );
            //cout<<start <<" "<<count<<endl;
        }
    }
    return count;
}

int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
      vector<vector<int>> adj (graph_nodes+1, vector<int>());;

    
    for(int i =0 ;i< graph_from.size() ;i++)
    {
        addEdge(graph_from[i], graph_to[i], adj);
    }
    vector<int> visi(graph_nodes+1, false);
    visi[0] = true;
    int ans =0;
    for( int i = 1 ; i<= graph_nodes ;i++ )
    {
       if(!visi[i]){
       int cnt =  dfs(adj,visi, i );
       
       ans += ceil(sqrt(cnt+1));
       //cout<<cnt<<endl;
       }
    }

     return ans;
}
int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

    string graph_nodes_edges_temp;
    getline(cin, graph_nodes_edges_temp);

    vector<string> graph_nodes_edges = split(rtrim(graph_nodes_edges_temp));

    int graph_nodes = stoi(graph_nodes_edges[0]);
    int graph_edges = stoi(graph_nodes_edges[1]);

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        string graph_from_to_temp;
        getline(cin, graph_from_to_temp);

        vector<string> graph_from_to = split(rtrim(graph_from_to_temp));

        int graph_from_temp = stoi(graph_from_to[0]);
        int graph_to_temp = stoi(graph_from_to[1]);

        graph_from[i] = graph_from_temp;
        graph_to[i] = graph_to_temp;
    }

    int result = connectedSum(graph_nodes, graph_from, graph_to);

    fout << result << "\n";

    fout.close();

    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
