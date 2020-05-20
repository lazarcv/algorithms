#include <iostream>
#include <vector>
#include <algorithm>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                std::vector<int> colors;
                int n;

        public:
                Graph(int n){
                        this->n=n;
                        visited.resize(n, false);
                        adjacency_list.resize(n);
                        colors.resize(n, -1);
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                        adjacency_list[v].push_back(u);
                }

                bool DFS(int u, int color){
                        visited[u]=true;
                        colors[u]=color;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(colors[*begin]==colors[u])
                                        return false;

                                if(!visited[*begin])
                                        if(!DFS(*begin, !color))
                                                return false;

                                begin++;
                        }
                        return true;
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

        if(g.DFS(0, 0)){
                std::cout<<"Graph is bipartite."<<std::endl;
        }
        else{
                std::cout<<"Graph is not biparite."<<std::endl;
        }
        return 0;
}
