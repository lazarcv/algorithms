#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

struct Node{
        Node(){
                left=right=nullptr;
        }
        int key;
        Node *left;
        Node *right;
};

void add_node(Node **root, int key){
        if(*root==nullptr){
                *root=new Node();
                (*root)->key=key;
                return;
        }

        if((*root)->key>key)
                add_node(&(*root)->left, key);
        else add_node(&(*root)->right, key);
}

void free_tree(Node *root){
        if(root==nullptr)
                return;

        free_tree(root->left);
        free_tree(root->right);

        delete root;
}

void BFS(Node *root, std::vector<int> &levels){
        std::queue<Node *> nodes;

        nodes.push(root);
        levels[root->key]=0;
        int curr_lvl=0;

        Node *tmp;

        while(nodes.size()){
                tmp=nodes.front();
                nodes.pop();

                if(tmp->left){
                        levels[tmp->left->key]=levels[tmp->key]+1;
                        nodes.push(tmp->left);
                }

                if(tmp->right){
                        levels[tmp->right->key]=levels[tmp->key]+1;
                        nodes.push(tmp->right);
                }

                if(levels[tmp->key]!=curr_lvl){
                        std::cout<<"\n";
                        curr_lvl++;
                }

                std::cout<<tmp->key<<" ";
        }
}
int main (){
        Node *root = nullptr;

        int n;
        std::cout<<"Enter number of nodes: ";
        std::cin>>n;
        if(n<0){
                std::cout<<"Number of nodes cant be less that 0.\n";
                exit(1);
        }
        std::vector<int> keys;
        keys.reserve(n);

        for (int i=0; i<n; i++){
                int x;
                std::cout<<"Input a node: ";
                std::cin>>x;
                keys.push_back(x);
                add_node(&root, x);
        }

        int max=*std::max_element(keys.begin(), keys.end());

        std::vector<int> levels(max);

        BFS(root, levels);

        std::cout << "\n";

        free_tree(root);

        return 0;
}

