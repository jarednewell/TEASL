#include <list>

#include "supporting_structures_EASL.cpp"

std::list<int> append_only_skip_list_range_search(int query_version_start, int query_version_end, Node* lastest_version){
    /*
    Searching algorithm for an append only skip-list version range query.
    Due to the nature of blockchain with immutability appending is the only valid method type.
    */

    bool finish = false;
    Node* this_version = lastest_version; // EASL Node (a version of a tracked identifier)
    std::list<int> version_data;

    while (!finish){

        if (query_version_end == lastest_version->Version){
            version_data.push_back(lastest_version->Value);
            break;
        }
        else if (this_version->pre_nodes.empty() || this_version->node_level.empty() == true){
            break;
        }
        // whist the skip list lists contain items then loop 
        while ((this_version->pre_nodes.empty() || this_version->node_level.empty()) == false){
            // checks the skip list nodes from the highest version to the lowest
            // sets the pointer
            Node* this_pre_node = this_version->pre_nodes.back();
            if (this_pre_node->Version == query_version_end){
                // find start of range
                while (this_version->Version >= query_version_start){
                    version_data.push_front(this_pre_node -> Value);
                    // process via bottom skip list level
                    this_version = this_pre_node->pre_nodes.front();

                }
                // version found so all is finished
                finish = true;
                break;
            }
            else if (this_pre_node->Version < query_version_end){
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
