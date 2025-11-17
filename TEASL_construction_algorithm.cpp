#include <list>
#include <vector>

#include "supporting_structures_TEASL.cpp"

bool TEASL_append(Node &version, std::vector<std::list<TEASL_Node>> &levels){
  // Builds TEASL Index from the EASL index one version at a time - user defined

  int index_level = 3; // This is the base of the TEASL index - user defined
  int highest_level = 0;
  bool version_processed = false;
  
  if (version.node_level.size() > 0){
      // sets the highest level, only if the height is 1 or more
      highest_level = version.node_level.back();
  }
  
  if (highest_level >= index_level){
      // if the highest level is greater or equal to the TEASL starting level

      // converts the level height to TEASL
      int relative_level = highest_level - index_level;

      // is adjusted because the TEASL starts at level 1
      int teasl_level = relative_level + 1;
      // returns a count of the levels existing in the TEASL index
      int current_levels = levels.size();
      
      if (teasl_level > current_levels) {        
          // adds the new level/s when required
          for (int k = 0; k < (teasl_level - current_levels); k++){
              std::list<TEASL_Node> new_list;
              levels.push_back(new_list);              
          }
      }

      // adds new node to an existing level (index adjusted to 0)
      TEASL_Node teasl_node;
      levels.at(relative_level).push_back(teasl_node);
      TEASL_Node* new_teasl_node = &(levels.at(relative_level).back());
      
      // if equal index level then no left pointer
      new_teasl_node->Version = version.Version;
      new_teasl_node->equal_node_pointer = &version;     

      if (teasl_level > 1){
          // set left pointer to last node in next level below that is not empty (updated to handle missing node below)
          int node_level_below = relative_level - 1;
          
          // Ensures the level is 0 and above
          while(node_level_below >= 0){
              // Begins inspection in levels below when list are empty - prevents exceptions
              if(levels.at(node_level_below).size() == 0){
                  // If empty go to next
                  node_level_below--;
                  continue;
              }
              // Checks if the node isn't the root node
              if(levels.back().back().Version != new_teasl_node->Version){
                  // checks the node above is smaller than the below node version - maintains tree constraints       
                  int node_level_above = relative_level + 1;
                  int node_version_above = 0;
                
                  // finds the node above if not already the highest
                  while(node_level_above < current_levels){
                      // Inital nodes could have list with a zero size
                      if(levels.at(node_level_above).size() != 0){
                          // largest node version is used to determine the revelent node
                          if(levels.at(node_level_above).back().Version > node_version_above){
                              node_version_above = levels.at(node_level_above).back().Version;
                              // if pointer already exist in upper version, maintains tree contraints
                          }
                      }
                      node_level_above++;
                  }
                  // compares the node versions and adds a pointer if required
                  if(levels.at(node_level_below).back().Version > node_version_above){
                      // writes the left pointer
                      new_teasl_node->left_pointer = &levels.at(node_level_below).back();
                  }
                  // continues to check for a relevant node version
                  if(levels.at(node_level_below).back().Version < node_version_above){
                      // find if a relevant version exist below
                      int level_below = node_level_below;
                      while(level_below != 0){
                          level_below--;
                          if(levels.at(level_below).back().Version > node_version_above){
                              new_teasl_node->left_pointer = &levels.at(level_below).back();
                              break;
                          }                        
                      }
                  }
                  break;   
              }
              else{
                  // writes the left pointer, if it is root node
                  new_teasl_node->left_pointer = &levels.at(node_level_below).back();
                  break;
              }
          }               
      }

      if (teasl_level < current_levels){
          // above removes out of bounds
        
          // New node is added as the first entry in the heighest level, so not orphaned and maintains the ternary-tree constraints
          TEASL_Node* relative_highest = &levels.back().back(); // start from the highest

          if (relative_highest->right_pointer == NULL){
              relative_highest->right_pointer = new_teasl_node;              
          }
          else {
              if (new_teasl_node->left_pointer == NULL){

                  // inspect levels above
                  int level = relative_level + 1;
                  int node_version_above = 0;
                  int node_level_above = 0;
                  
                  while(level < current_levels){
                      // Inital nodes could have list with a zero size
                      if(levels.at(level).size() != 0){
                          // largest node version is used to determine the revelent node
                          if(levels.at(level).back().Version > node_version_above){
                              node_version_above = levels.at(level).back().Version;
                              // if pointer already exist in upper version, maintains tree contraints
                              node_level_above = level;
                          } 
                      }
                      level++;
                  }
                  levels.at(node_level_above).back().right_pointer = new_teasl_node;                  
              }
              else{
                  int relative_level = current_levels;
                  // starts at the highest and works down level by level
                  while(relative_level > 0){
                      // allows to re-write right pointer set to prevent orphaned node
                      if (relative_highest->right_pointer != NULL ){
                          if (relative_highest->right_pointer->Version == new_teasl_node->left_pointer->Version){
                              // checks if there is a pointer existing already to the version
                              relative_highest->right_pointer = new_teasl_node;
                              break;
                          }
                      }
                      relative_level--;
                      relative_highest = &levels.at(relative_level).back();
                  }
              }     
          }
      }       
  }
  version_processed = true;
  return version_processed;
}
