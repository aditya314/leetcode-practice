class Solution {
private:
    enum STATE { NEW, PROCESS, TRUE, FALSE };
    bool can_make_recipe(string& recipe, vector<string>& ingredients, vector<vector<string>>& ingredients_list, unordered_set<string>& supply_set,unordered_map<string, int>& recipe_index_map, vector<string>& answer, unordered_map<string, STATE>& recipe_state_map){
        //cout<<"Checking for : "<<recipe<<endl;
        if(recipe_state_map[recipe] == TRUE)  return true;
        if(recipe_state_map[recipe] == FALSE)  return false;
        if(recipe_state_map[recipe] == PROCESS)  return false;
        
        //cout<<"Not found in set : " <<recipe<<endl;
        recipe_state_map[recipe] = PROCESS;
        for(string item: ingredients){
            //cout<<"Checked for ingredient : "<<item<<" "<<endl;
            if(supply_set.find(item) == supply_set.end()){
                if(recipe_index_map.find(item) != recipe_index_map.end()){
                    if(recipe_state_map[item] == PROCESS || recipe_state_map[item] == FALSE){
                        recipe_state_map[recipe] = FALSE;
                        return false;
                    }
                    if(recipe_state_map[item] == NEW && !can_make_recipe(item, ingredients_list[recipe_index_map[item]], ingredients_list, supply_set, recipe_index_map, answer, recipe_state_map)){
                        recipe_state_map[recipe] = FALSE;
                        return false;
                    }
                    
                }
                else{
                    recipe_state_map[recipe] = FALSE;
                    return false;
                }
            }
        }
        //cout<<"Added : "<<recipe<<endl;
        recipe_state_map[recipe] = TRUE;       
        answer.push_back(recipe);
        return true;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supply_set(supplies.begin(), supplies.end());
        unordered_map<string, int> recipe_index_map;
        unordered_map<string, STATE> recipe_state_map;
        int n = recipes.size();
        for(int i = 0; i < n; i++){
            recipe_index_map[recipes[i]] = i;
            recipe_state_map[recipes[i]] = NEW;
        } 
        
        
        vector<string> answer;
        for(int i = 0 ; i < n; i++){
            can_make_recipe(recipes[i], ingredients[i], ingredients, supply_set, recipe_index_map, answer, recipe_state_map);
        }
        return answer;
    }
};