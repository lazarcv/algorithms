#include <iostream>
#include <vector>
#include <climits>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                int n;
                int min_num_of_edges;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                        min_num_of_edges=INT_MAX;
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                }

                void DFS(int u, int v, int curr_num_of_edges){
                        if(u==v){
                                if(curr_num_of_edges<min_num_of_edges)
                                        min_num_of_edges=curr_num_of_edges;
                                return;
                        }

                        visited[u]=true;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(!visited[*begin])
                                        DFS(*begin, v, curr_num_of_edges+1);
                                begin++;
                        }

                        visited[u]=false;
                }

                int get_min_num_of_edges(){
                        return min_num_of_edges;
                }
};

int main(){
        int n;
        std::cout<<"Number of nodes: ";
        std::cin>>n;

        Graph g(n);

        int from;
        std::cout<<"DFS from node: ";
        std::cin>>from;
        if(from<0 || from>=n){
                std::cerr<<"Number must be between 0 and "<<n<<"."<<std::endl;
                exit(1);
        }

        int to;
        std::cout<<"DFS to node: ";
        std::cin>>to;
        if(to<0 || to>=n){
                std::cerr<<"Number must be between 0 and "<<n<<"."<<std::endl;
                exit(1);
        }

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

        g.DFS(from, to, 0);
        std::cout<<"Minimal number of edges from node "<<from<<" to node "<<to<<" is "<<g.get_min_num_of_edges()<<"."<<std::endl;

        return 0;
}
