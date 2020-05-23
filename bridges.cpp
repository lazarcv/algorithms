#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                std::vector<int> parents;
                std::vector<int> times;
                std::vector<int> lower_times;
                int time;
                int n;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                        parents.resize(n, -1);
                        times.resize(n, -1);
                        lower_times.resize(n, -1);
                        time=0;
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                        adjacency_list[v].push_back(u);
                }

                void DFS(int u){
                        visited[u]=true;
                        times[u]=lower_times[u]=time;

                        time++;
                        int children=0;

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                if(!visited[*begin]){
                                        parents[*begin]=u;
                                        DFS(*begin);
                                        children++;

                                        lower_times[u]=std::min(lower_times[*begin], lower_times[u]);
                                        if(times[u]<lower_times[*begin])
                                                std::cout<<u<<" -> "<<*begin<<"\n";
                                }
                                else if(*begin!=parents[u]){
                                        lower_times[u]=std::min(lower_times[u], lower_times[*begin]);
                                }

                                begin++;
                        }
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

        return 0;
}
