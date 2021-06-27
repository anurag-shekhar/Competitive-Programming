/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignMovieRentalSystem.cpp
 * Created on : Sun Jun 27 2021
 ****************************************************************
 */

class MovieRentingSystem {
public:
    unordered_map<int, set<vector<int> > > m;
    unordered_map<int, unordered_map<int, int> > priceMap;
    set<vector<int> > rentReport;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        m.clear();
        rentReport.clear();
        priceMap.clear();
        
        for(auto v : entries)
        {
            m[v[1]].insert({v[2], v[0]});
            priceMap[v[1]][v[0]] = v[2];
        }
    }
    
    vector<int> search(int movie) {
        
        vector<int> res;
        int count = 0; 
        for(auto v : m[movie])
        {
            count++;
            if(count > 5)
                break;
            res.push_back(v[1]);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        rentReport.insert({priceMap[movie][shop],shop,movie});
        m[movie].erase({priceMap[movie][shop], shop});
    }
    
    void drop(int shop, int movie) {
        m[movie].insert({priceMap[movie][shop], shop});
        rentReport.erase({priceMap[movie][shop],shop,movie});
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int> > res;
        int count = 0; 
       
        for(auto v : rentReport)
        {
            count++;
            if(count > 5)
                break;
            res.push_back({v[1],v[2]});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
