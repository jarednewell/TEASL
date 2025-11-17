#include <list>
#include <vector>

#include "supporting_structures_TEASL.cpp"

Node* TEASL_traversal(int search_version, std::vector<std::list<TEASL_Node>> &levels){

    TEASL_Node* current_node = &levels.back().back();
    Node* closest_version;
    Node* fallback_version;

    while (true){

        if (current_node->Version >= search_version){
            fallback_version = current_node->equal_node_pointer;
        }

        if (current_node->Version == search_version || (current_node->left_pointer == NULL && current_node->right_pointer == NULL)){
            closest_version = current_node->equal_node_pointer;
            break;
        }
        else if (current_node->Version > search_version){
            if(current_node->left_pointer != NULL){           
                current_node = current_node->left_pointer;
                continue;
            }
            else {         
                closest_version = current_node->equal_node_pointer;
                break;
            }
        }
        else if (current_node->Version < search_version){
            if (current_node->right_pointer != NULL){               
                current_node = current_node->right_pointer;
                continue;
            }
            else {
                closest_version = current_node->equal_node_pointer;
                break;
            }
        }
    }

    if (closest_version->Version < search_version){
        closest_version = fallback_version;
    }
    return closest_version;
}
