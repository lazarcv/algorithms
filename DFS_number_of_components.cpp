#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                int n;
                int min_num_of_edges;
                int num_of_components;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                        num_of_components=1;
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                        adjacency_list[v].push_back(u);
                }

                void DFS(int u){
                        visited[u]=true;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(!visited[*begin])
                                        DFS(*begin);
                                begin++;
                        }
                }

                int get_num_of_components(){
                        for(int i=0; i<n; i++){
                                if(!visited[i]){
                                        num_of_components++;
                                        DFS(i);
                                }
                        }
                        return num_of_components;
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

        g.DFS(0);
        std::cout<<g.get_num_of_components()<<std::endl;
        return 0;
}
