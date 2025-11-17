#include "supporting_structures_EASL.cpp"

bool append_only_skip_list_search(int query_version, Node* lastest_version){
    /*
    Searching algorithm for an append only skip-list.
    Due to the nature of blockchain with immutability appending is the only valid method type.
    */

    bool finish = false;
    Node* this_version = lastest_version; // EASL Node (a version of a tracked identifier)
    bool version_data;

    while (!finish){
        // if so no pointers exist so it must be the first node version in the NVLL
        if ((this_version->pre_nodes.empty() || this_version->node_level.empty()) == true){
            // the skip list is exhausted, could not locate the data
            version_data = false;
            finish = true;
        }
        // whist the skip list lists contain items then loop 
        while ((this_version->pre_nodes.empty() || this_version->node_level.empty()) == false){
            // checks the skip list nodes from the highest version to the lowest
            // sets the pointer
            Node* this_pre_node = this_version->pre_nodes.back();
            if (this_pre_node->Version == query_version){
                // version found so all is finished
                finish = true;
                version_data = true;
                break;
            }
            else if (this_pre_node->Version < query_version){
                // remove the left pointer in the vector
                this_version->pre_nodes.pop_back();
                this_version->node_level.pop_back();
            }
            else {
                // set current version is updated to the pre_node pointer version
                this_version = this_pre_node;
                // exits the inner while loop
                break;
            }
        }
    }
    return version_data;
}
