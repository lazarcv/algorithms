#include <iostream>
#include <vector>
#include <queue>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                std::vector<int> in_degrees;
                int n;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                        in_degrees.resize(n, 0);
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                        in_degrees[v]++;
                }

                void topological_sorting(){
                        std::queue<int> nodes;

                        for(int i=0; i<n; i++)
                                if(!in_degrees[i])
                                        nodes.push(i);

                        int tmp;

                        while(nodes.size()){
                                tmp=nodes.front();

                                nodes.pop();
                                std::cout<<tmp<<" ";
                        
                                for(int node:adjacency_list[tmp]){
                                        in_degrees[node]--;
                                        if(!in_degrees[node])
                                                nodes.push(node);
                                }
                        }
                        std::cout<<std::endl;
                }
};

int main(){
        int n;
        std::cout<<"Number of nodes: ";
        std::cin>>n;

        Graph g(n);

        int num_of_edges;
        std::cout<<"Number of edges: ";
        std::cin>>num_of_edges;

        for(int i=0; i<num_of_edges; i++){
                int x, y;
                std::cout<<"From which edge to which edge? ";
                std::cin>>x>>y;
                if(x<0 || x>=n || y<0 || y>=n){
                        std::cerr<<"Numbers must be between 0 and "<<n<<"."<<std::endl;
                        exit(1);
                }
                g.add_edge(x, y);
        }

        g.topological_sorting();
        return 0;
}
