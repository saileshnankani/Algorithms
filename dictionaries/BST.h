#ifndef __BST__
#define __BST__

template<typename K = int>
class Node{
    
}

template<typename K = int>
class BST{
    
}

<<<<<<< HEAD
=======
        friend std::ostream& operator<<(std::ostream& out, const BST& other){
            if(other.root){
                std::cout<<other.root->left<<std::endl;
                out<<other.root->left<<"("+ std::to_string(other.root->element.first)+","+ std::to_string(other.root->element.second)+") "<<other.root->right;
            }
            else{
                out<<"";
            }
        }
};
>>>>>>> 154c0ba... Cleaned up

#endif