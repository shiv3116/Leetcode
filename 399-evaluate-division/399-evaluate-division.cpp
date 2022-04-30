class DSU{
private:
    
    vector<int> root;
    vector<int> rank;
    vector<double> mult;
    
public:
    
    DSU(int _size){
        for(int i = 0; i < _size; i++){
            root.push_back(i);
            rank.push_back(1);
            mult.push_back(1);
        }
    }
    
    pair<int, double> find(int x){
        if(x == root[x]) return {x , 1};
        int rootX;
        double multX;
        tie(rootX, multX) = find(root[x]);
        
        return {root[x] = rootX, mult[x] *= multX};
    }
    
    void unionSet(int x, int y, double div){
        int rootX = find(x).first;
        int rootY = find(y).first;
        
        if(rootX == rootY) return;
        
        if(rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
        }
        else if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            mult[rootY] = mult[x] / (mult[y] * div);
        }
        else{
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
            rank[rootY]++;
        }
    }
    
    bool isConnected(int x, int y){
        return find(x).first == find(y).first;   
    }
};


class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int id = 0;
        vector<double> answers;
        unordered_map<string, int> ids;
        for(auto& equation : equations){
            if(ids.find(equation[0]) == ids.end()) ids[equation[0]] = id++;
            if(ids.find(equation[1]) == ids.end()) ids[equation[1]] = id++;
        }
        
        DSU dsu = *new DSU(id);
        
        for(int i = 0; i < equations.size(); i++){
            dsu.unionSet(ids[equations[i][0]], ids[equations[i][1]], values[i]);
        }
        
        for(auto& query : queries){
            if(ids.find(query[0]) == ids.end() || ids.find(query[1]) == ids.end()){
                answers.push_back(-1);
            }
            else{
                int x = ids[query[0]];
                int y = ids[query[1]];
                if(!dsu.isConnected(x, y)) answers.push_back(-1);
                else answers.push_back(dsu.find(x).second / dsu.find(y).second);
            }
        }
        
        return answers;
        
    }
};