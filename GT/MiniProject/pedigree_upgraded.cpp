# include <bits/stdc++.h>
# include <string>
using namespace std;

class individual{
    public:
    // string code = "";
    int isColorBlind = 0;
    int gender = 0;
    map<int, vector<string>> combinations;
    
};

individual* createIndividual(){
individual* newNode = new individual;
cout<<"Enter your gender (0->Male/1->Female): ";
cin>>newNode->gender;
cout<<"Are u colour blind (1->Yes/0->No): ";
cin>>newNode->isColorBlind;
return newNode; 
}

individual* createSpouse(individual* ind){
individual* newNode = new individual;
if(ind->gender == 0){
    newNode->gender = 1;
}
else if(ind->gender == 1){
    newNode->gender = 0;
}
cout<<"Is your spouse colour blind (1->Yes/0->No): ";
cin>>newNode->isColorBlind;
return newNode; 
}

vector<vector<int>> rtn_bipartite(vector<int> parent1, vector<int> parent2){
    vector<vector<int>> adjList(parent1.size()+parent2.size());
    for(auto it1 : parent1) adjList[it1] = parent2;
    for(auto it2 : parent2) adjList[it2] = parent1;
    return adjList;
}

vector<vector<int>> rtn_edges(vector<vector<int>> adjList, int p){
    vector<vector<int>> edges;
    int x = 0;
    for(auto it : adjList){
        for(auto it1 : it){
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(it1);
            edges.push_back(edge);
        }
        if(x==p) break;
        x++;
    }
    return edges;
}

vector<string> decode_edges(map<int,string> encoded_gametes, vector<vector<int>> edges){
    vector<string> vect;
    for(auto edge: edges){
        string str = "";
        for(auto x : edge){
            str += encoded_gametes[x];
        }
        vect.push_back(str);
    }
    return vect;
}

vector<string> functionx(string p1, string p2){
    vector<int> parent1,parent2;
    map<int,string> encoded_gametes;
    int x = 0,p = 0;
    for(int i = 0; i < p1.length(); i+=2){
        encoded_gametes[x] = p1.substr(i,2);
        parent1.push_back(x);
        x++;
    }
    p = x-1;
    for(int j = 0; j < p2.length(); j+=2){
        encoded_gametes[x] = p2.substr(j,2);
        parent2.push_back(x); 
        x++;
    }
    vector<vector<int>> bipartite_graph = rtn_bipartite(parent1,parent2);
    vector<vector<int>> edges = rtn_edges(bipartite_graph,p);
    vector<string> vect = decode_edges(encoded_gametes, edges);
    return vect;
}


vector<string> generate_meiosis_combinations(individual* ind1, individual *ind2){
    vector<vector<string>> cbntn_clrBlnd(2,vector<string>(2));
    cbntn_clrBlnd[0][0] = "XnYn";
    cbntn_clrBlnd[0][1] = "XcYn";
    cbntn_clrBlnd[1][0] = "XnXnXnXc";
    cbntn_clrBlnd[1][1] = "XcXc";
    string parent1 = cbntn_clrBlnd[ind1->gender][ind1->isColorBlind];
    string parent2 = cbntn_clrBlnd[ind2->gender][ind2->isColorBlind];
    vector<string> vect = functionx(parent1, parent2);
    return vect;
}

void calculate_print_probability(vector<string> vect){
    vector<string> male_progeny;
    vector<string> female_progeny;
    for(auto str: vect){
        if(str[0] == str[2]){
            female_progeny.push_back(str);
        }
        else{
            male_progeny.push_back(str);
        }
    }
    int male_color_blind = 0, female_color_blind = 0, female_carrier = 0;
    for(auto str: male_progeny){
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'c'){
                male_color_blind++;
            }
        }
    }
    float total_males = male_progeny.size();
    cout<<"Probability of male progeny being color blind = "<<(male_color_blind/total_males)*100<<"%"<<endl;
    cout<<"Probability of male progeny not being color blind = "<<((total_males-male_color_blind)/total_males)*100<<"%"<<endl;
    for(auto str: female_progeny){
        int count_c = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'c'){
                count_c++;
            }
        }
        if(count_c == 1){
            female_carrier++;
        }
        else if(count_c == 2){
            female_color_blind++;
        }
    }
    float total_females = female_progeny.size();
    cout<<"Probability of female progeny being color blind = "<<(female_color_blind/total_females)*100<<"%"<<endl;
    cout<<"Probability of female progeny being carrier(but not affected) of the trait = "<<(female_carrier/total_females)*100<<"%"<<endl;
    cout<<"Probability of female progeny being absolutely normal(neither affected nor carrier) = "<<((total_females-(female_color_blind+female_carrier))/total_females)*100<<"%"<<endl;
}

int main(){
    cout<<"Lets calculate probabilty of your offspring getting color blindness..."<<endl;
    cout<<"U need to just answer some basic questions..."<<endl;    
    individual* me = createIndividual();
    individual* mySpouse = createSpouse(me);
    vector<string> vect = generate_meiosis_combinations(me,mySpouse);
    for(auto str: vect){
        cout<<str<<endl;
    }
    calculate_print_probability(vect);
    return 0;
}