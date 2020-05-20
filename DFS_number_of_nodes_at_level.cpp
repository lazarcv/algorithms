#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                int n;
                int num_of_nodes_at_level;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                        num_of_nodes_at_level=0;
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                }

                void DFS(int u, int lvl, int curr_lvl){
                        visited[u]=true;

                        if(curr_lvl==lvl)
                                num_of_nodes_at_level++;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(!visited[*begin])
                                        DFS(*begin, lvl, curr_lvl+1);
                                begin++;
                        }
                }

                int get_num_of_nodes_at_level(){
                        return num_of_nodes_at_level;
                }
};

int main(){
        int n;
        std::cout<<"Number of nodes: ";
        std::cin>>n;

        Graph g(n);

        int lvl;
        std::cout<<"What level interests you? ";
        std::cin>>lvl;

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

        g.DFS(0, lvl, 0);
        std::cout<<"There are "<<g.get_num_of_nodes_at_level()<<" nodes on level "<<lvl<<"."<<std::endl;

        return 0;
}
