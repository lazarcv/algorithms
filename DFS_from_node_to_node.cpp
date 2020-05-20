#include <iostream>
#include <vector>

class Graph{
        private:
                std::vector<std::vector<int>> adjacency_list;
                std::vector<bool> visited;
                int n;
                bool found;

        public:
                Graph(int n){
                        this->n=n;
                        adjacency_list.resize(n);
                        visited.resize(n, false);
                }

                void add_edge(int u, int v){
                        adjacency_list[u].push_back(v);
                }

                bool DFS(int u, int v, std::vector<int> &result){
                        if(u==v){
                                result.push_back(v);
                                found=true;
                                return true;
                        }

                        visited[u]=true;
                        result.push_back(u);

                        auto begin=adjacency_list[u].begin();
                        auto end=adjacency_list[u].end();

                        while(begin!=end){
                                bool ret_val=false;

                                if(!visited[*begin] && !found)
                                        ret_val=DFS(*begin, v, result);
                                if(ret_val)
                                        return true;

                                result.pop_back();

                                begin++;
                        }
                        return false;
                }

                bool get_found(){
                        return found;
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
        
        std::vector<int> result;
        g.DFS(from, to, result);

        if(!g.get_found())
                std::cout<<"There is no path from node "<<from<<" to node "<<to<<"."<<std::endl;
        else{
                int i;
                for(i=0; i<result.size()-1; i++)
                        std::cout<<result[i]<<" -> ";

                std::cout<<result[i]<<std::endl;
        }

        return 0;
}
