#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

class disjoint_set {
    int size;
    vector<int> parent;
    vector<int> rank; //Height of each vertex is saved

    public :

    disjoint_set(int siz) : size(siz){
        parent.resize(size);
        rank.resize(size);
        for(int i=0; i < size; ++i) {
                parent[i]=i;
                rank[i]=1;
        }
    }

    bool do_union(int u, int v) { 
        int p1 = find(u);
        int p2 = find(v);
        if(p1 == p2)
            return false;  //Already in same set
        
        //Union by rank
        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] = std::max(rank[p1], 1 + rank[p2]);
            rank[p2] = rank[p1];
        } else {
            parent[p1] = p2;
            rank[p2] = std::max(rank[p2], 1 + rank[p1]);
            rank[p1] = rank[p2];
        }

        return true;
    }

    //Return the parent of vertex v
    int find(int v) {
        if(v == parent[v])
            return v;
        else {
            int p = find(parent[v]);
            parent[v]=p;  //Path compression
            return p;
        }
    }

};

struct edge {int s; int d; int w;};

int kruskals(int n, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    disjoint_set disj_set(n+1);

    int m = g_from.size();
    vector<edge> edges_v;
    for(int i =0; i < m; ++i) {
        edges_v.push_back({g_from[i], g_to[i], g_weight[i]});
    }
    auto comp = [](const edge & e1, const edge & e2)->bool{
        if(e1.w < e2.w)
            return true;
        else
            return false;
        
    };

    std::sort(edges_v.begin(), edges_v.end(), comp);
    long long int mst_weight=0;
    int edges_selected = 0;
    for(const auto & e : edges_v) {
        if(disj_set.do_union(e.s, e.d))
             { 
                 //cout << e.s << " " << e.d << "  "<<e.w <<"\n";
                 mst_weight  += e.w;
                 ++edges_selected;
             }
             if(edges_selected == n-1)
                break;
    }
    //std::cout << mst_weight<<"\n";

    return mst_weight;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    fout << kruskals(g_nodes, g_from, g_to, g_weight);

    

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
