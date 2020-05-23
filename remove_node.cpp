#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                int n;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                        adjacency_list[v].push_back(u);
                }

                void DFS(int u){
                        visited[u]=true;

                        bool is_leaf=true;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(!visited[*begin]){
                                        DFS(*begin);
                                        is_leaf=false;
                                }

                                begin++;
                        }

                        if(is_leaf)
                                std::cout<<u<<std::endl;
                }
};

int main(){
        int n;
        std::cout<<"Number of nodes: ";
        std::cin>>n;

        if(n<0){
                std::cout<<"Number of nodes cant be less than 0.\n";
                exit(1);
        }

        Graph g(n);

        int num_of_edges;
        std::cout<<"Number of edges: ";
        std::cin>>num_of_edges;

        if(num_of_edges<0){
                std::cout<<"Number of edges cant be less than 0.\n";
                exit(1);
        }

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
        
        g.DFS(0);

        return 0;
}
