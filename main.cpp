#include<iostream>
#include<vector>

using namespace std;


class Graph{
    private:
    vector<vector<int>> graph_nodes;

    vector<int> subtree_sizes;

    bool *visited;


    public:
    Graph(int size){
        graph_nodes.resize(size);
        subtree_sizes.resize(size);
        visited = new bool[size];
    }

    void add_connection(int id1, int id2){
        graph_nodes[id1-1].push_back(id2-1);
        graph_nodes[id2-1].push_back(id1-1);
    }

    void bfs_print(int start){
        cout<<start<<endl;

    }

    void dfs(int current_node){
        if(graph_nodes[current_node].size() == 0){
            subtree_sizes[current_node] = 1;
            return;
        }

        for(int i=0; i<graph_nodes[current_node].size();i++){
            if(!visited[graph_nodes[current_node][i]]){
                dfs(graph_nodes[current_node][i]);
            }
        }

        // Sum all subtrees
        int current_sum = 0;
        for(int i=0; i<graph_nodes[current_node].size();i++){
            current_sum += subtree_sizes[]
        }

    }

    void rec_print(int current, int previous){
        cout<<current+1<<" ";
        for(int i=0; i<graph_nodes[current].size() ; i++){
            if(graph_nodes[current][i] != previous){
                rec_print(graph_nodes[current][i],current);
            }
            
        }
    }
};


int main(){
    Graph net_graph(4);
    net_graph.add_connection(1,2);
    net_graph.add_connection(2,4);
    net_graph.add_connection(1,3);
    net_graph.rec_print(2,2);
    return 0;
}