#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacencty_list;
                std::vector<bool> visited;
                int n;

        public:
                Graph(int n){
                        this->n=n;
                        adjacencty_list.resize(n);
                        visited.resize(n, false);
                }

                void add_edge(int u, int v){
                        adjacencty_list[u].push_back(v);
                }

                bool have_cycle(int u){
                        visited[u]=true;

                        auto begin=adjacencty_list[u].begin();
                        auto end=adjacencty_list[u].end();

                        while(begin!=end){
                                if(visited[*begin])
                                        return true;
                                else if(have_cycle(*begin))
                                        return true;

                                begin++;
                        }

                        visited[u]=false;
                        return false;
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
        
        if(g.have_cycle(0)){
                std::cout<<"This graph have atleast 1 cycle.\n";
        }
        else{
                std::cout<<"This graph doesnt have a cycle.\n";
        }
        return 0;
}
