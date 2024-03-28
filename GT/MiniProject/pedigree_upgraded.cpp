# include <bits/stdc++.h>
# include <string>
using namespace std;

class individual{
    public:
    int hasGotDisease = 0;
    int gender = 0;
    map<int, vector<string>> combinations;   
};

individual* createIndividual(int disease, map<int,string> disease_map){
individual* newNode = new individual;
cout<<"Enter your gender (0->Male/1->Female): ";
cin>>newNode->gender;
cout<<"Do u have "<<disease_map[disease]<<" (1->Yes/0->No): ";
cin>>newNode->hasGotDisease;
return newNode; 
}

individual* createSpouse(individual* ind,int disease, map<int, string> disease_map){
individual* newNode = new individual;
if(ind->gender == 0){
    newNode->gender = 1;
}
else if(ind->gender == 1){
    newNode->gender = 0;
}
cout<<"Do your spouse have"<<disease_map[disease]<<"(1->Yes/0->No): ";
cin>>newNode->hasGotDisease;
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


vector<string> generate_meiosis_combinations(individual* ind1, individual *ind2, int disease, map<int,string> disease_map){
    // vector<vector<string>> cbntn_clrBlnd(2,vector<string>(2));
    vector<vector<vector<string>>> combinations(3,vector<vector<string>>(2,vector<string>(2)));
    combinations[0][0][0] = "XnYn";
    combinations[0][0][1] = "XcYn";
    combinations[0][1][0] = "XnXnXnXc";
    combinations[0][1][1] = "XcXc";
    combinations[1][0][0] = "XnYn";
    combinations[1][0][1] = "XcYn";
    combinations[1][1][0] = "XnXnXnXc";
    combinations[1][1][1] = "XcXc";
    combinations[2][0][0] = "HnHnHnHc";
    combinations[2][0][1] = "HcHc";
    combinations[2][1][0] = "HnHnHnHc";
    combinations[2][1][1] = "HcHc";

    string parent1 = combinations[disease][ind1->gender][ind1->hasGotDisease];
    string parent2 = combinations[disease][ind2->gender][ind2->hasGotDisease];
    vector<string> vect = functionx(parent1, parent2);
    return vect;
}

void calculate_print_probability_xlinked(vector<string> vect, int disease, map<int,string> disease_map){
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
    int male_isAffected = 0, female_isAffected = 0, female_carrier = 0;
    for(auto str: male_progeny){
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'c'){
                male_isAffected++;
            }
        }
    }
    float total_males = male_progeny.size();
    cout<<"Probability of male progeny having "<<disease_map[disease]<<" = "<<(male_isAffected/total_males)*100<<"%"<<endl;
    cout<<"Probability of male progeny having "<<disease_map[disease]<<" = "<<((total_males-male_isAffected)/total_males)*100<<"%"<<endl;
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
            female_isAffected++;
        }
    }
    float total_females = female_progeny.size();
    cout<<"Probability of female progeny having "<<disease_map[disease]<<" = "<<(female_isAffected/total_females)*100<<"%"<<endl;
    cout<<"Probability of female progeny being carrier(but not affected) of the trait = "<<(female_carrier/total_females)*100<<"%"<<endl;
    cout<<"Probability of female progeny being absolutely normal(neither affected nor carrier) = "<<((total_females-(female_isAffected+female_carrier))/total_females)*100<<"%"<<endl;
}
void calculate_print_probability_autosomal(vector<string> vect, int disease, map<int,string> disease_map){
    // vector<string> progeny = vect;
    int affected = 0, carrier = 0, normal = 0;
    int count_c = 0;
    for(auto str: vect){
        count_c = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'c') count_c++;
            cout<<"count_c = "<<count_c<<endl;
        }
        if(count_c == 0) normal++;
        else if(count_c == 1) carrier++;
        else if(count_c == 2) affected++;
    }
    float total_progeny = normal+carrier+affected;
    cout<<"Probability of progeny having "<<disease_map[disease]<<" = "<<affected<<"   "<<(affected/total_progeny)*100<<"%"<<endl;
    cout<<"Probability of progeny being carrier(but not affected) of the trait = "<<carrier<<"  "<<(carrier/total_progeny)*100<<"%"<<endl;
    cout<<"Probability of progeny being absolutely normal(neither affected nor carrier) = "<<normal<<"   "<<(normal/total_progeny)*100<<"%"<<endl;
}

int main(){
    cout<<"To calculate probabiltiy of your offspring getting any of the following disease..."<<endl;
    int choice = 0;
    cout<<"_ _ _Enter 0 for color blindness_ _ _\n_ _ _Enter 1 for hemophilia_ _ _\n_ _ _Enter 2 for sickle cell anemia_ _ _"<<endl;
    map<int, string> diseaseMap;
    diseaseMap[0] = "color blindness";
    diseaseMap[1] = "hemophilia";
    diseaseMap[2] = "sickle cell anemia";
    cout<<"Enter choice: ";
    cin>>choice;
    
    individual *me,*mySpouse;
    vector<string> vect;   
    switch(choice){
        case 0:
            me = createIndividual(0,diseaseMap);
            mySpouse = createSpouse(me,0,diseaseMap);
            vect = generate_meiosis_combinations(me,mySpouse,0,diseaseMap);  
            calculate_print_probability_xlinked(vect,0,diseaseMap);
            break;
        case 1:
            me = createIndividual(1,diseaseMap);
            mySpouse = createSpouse(me,1,diseaseMap);
            vect = generate_meiosis_combinations(me,mySpouse,1,diseaseMap);  
            calculate_print_probability_xlinked(vect,1,diseaseMap);
            break;
        case 2:
            me = createIndividual(2,diseaseMap);
            mySpouse = createSpouse(me,2,diseaseMap);
            vect = generate_meiosis_combinations(me,mySpouse,2,diseaseMap);
            for(auto str: vect){
                cout<<str<<endl;
            }
            calculate_print_probability_autosomal(vect,2,diseaseMap);
            break;
        default:
            cout<<"Invalid choice!";
            return 0;
    }
    return 0;
}