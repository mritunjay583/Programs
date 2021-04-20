#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class graph
{
private:
    /* data */
    int numberOfVertices;
    vector<int> *g;
public:
    graph(/* args */){
        numberOfVertices=0;
        g=NULL;
    }
    ~graph(){
        free(g);
    }
    pair<vector<int>*,int>  getGraph(string,int);
};


std::string& ltrim(std::string& s)
{
	auto it = std::find_if(s.begin(), s.end(),
					[](char c) {
						return !std::isspace<char>(c, std::locale::classic());
					});
	s.erase(s.begin(), it);
	return s;
}

std::string& rtrim(std::string& s)
{
	auto it = std::find_if(s.rbegin(), s.rend(),
					[](char c) {
						return !std::isspace<char>(c, std::locale::classic());
					});
	s.erase(it.base(), s.end());
	return s;
}

std::string& trim(std::string& s)
{
	return ltrim(rtrim(s));
}


pair<vector<int>*,int> graph ::getGraph(string input,int type=0){
    vector<pair<int,int> > edges;
    fstream fin;
    fin.open(input);
    string line;
    int flag=0;
    int u,v;
    while(fin)
    {
        getline(fin,line);
        
        trim(line);
        if(line.size()==0)
            break;
            
        if(flag==0){
            stringstream parser(line);
            parser >> numberOfVertices;
            flag=1;
        }
        else{
            int i=0;
            string temp="";
            while(i < line.size()){
                if(line[i]!=' '){
                    temp+=line[i];
                }
                else{
                    stringstream parser(temp);
                    parser >> u;
                    temp.clear();
                }
                i++;
            }
            stringstream parser(temp);
            parser >> v;
            try{
                if(u >=0 && u<numberOfVertices && v>=0 && v< numberOfVertices)
                    edges.push_back(make_pair(u,v));
                else{
                    throw "wrong input";
                }
            }
            catch(...){
                cout<<"wrong input"<<endl;
            }    
        }
    }

    g=new vector<int>[numberOfVertices];
    for(int i=0;i<edges.size();i++){
        // cout<<edges[i].first<<" "<<edges[i].second<<endl;
        g[edges[i].first].push_back(int(edges[i].second));
        if(type==1){
            g[edges[i].second].push_back(int(edges[i].first));
        }
    }

    return make_pair(g,numberOfVertices);
}

void print(vector<int>* graph,int totalVertex){
    // system("cls");
    for(int i=0;i<totalVertex;i++){
        cout<<i<<" : ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}


// int main(){
//     string inputFile="input.txt";
//     graph g;
//     pair<vector<int>*,int> data=g.getGraph(inputFile,1);
//     int totalVertex=data.second;
//     vector<int> *graph=data.first;
//     print(graph,totalVertex);
// }




