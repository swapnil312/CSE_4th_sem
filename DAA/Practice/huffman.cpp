# include <bits/stdc++.h>
using namespace std;

class HuffNode{
    public:
    char c;
    int f;
    HuffNode *left, *right;
    HuffNode(char c, int f){
        left = right = NULL;
        this->c = c;
        this->f = f;
    }
};

struct compare{
    bool operator()(HuffNode* left, HuffNode* right){
        return left->f > right->f;
    }
};

void printTree(HuffNode *node, string str){
    if(!node) return;
    if(node->c != '#') cout<<endl<<node->c<<"\t"<<str<<endl;
    printTree(node->left, str+"0");
    printTree(node->right, str+"1");
}

void genHuffCode(char *ch, int *freq, int size){
    priority_queue<HuffNode*,vector<HuffNode*>, compare> q;

    for(int i = 0; i < size; i++){
        HuffNode* node = new HuffNode(ch[i],freq[i]);
        q.push(node);
    }

    HuffNode *left, *right;

    while(q.size() != 1){
        left = q.top();
        q.pop();

        right = q.top();
        q.pop();

        HuffNode *top = new HuffNode('#', left->f+right->f);
        top->left = left;
        top->right = right;
        q.push(top);
    }

    printTree(q.top(),"");

}

int main(){

    int n;
    cout<<"Enter number of charcters: ";
    cin>>n;
    char ch[n];
    int f[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter character "<<(i+1)<<": ";
        cin>>ch[i];
        cout<<"Enter frequency of "<<ch[i]<<": ";
        cin>>f[i];
    }
    genHuffCode(ch, f, n);
    return 0;
}