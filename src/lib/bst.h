#ifndef __INTERVIEW_BOOK_BST_H_
#define __INTERVIEW_BOOK_BST_H_

template<typename T>
/*! \brief Node structure of BST
 */
class BSTNode
{
public:
  T data; //< internal data type
  BSTNode* left; //< left sub-tree
  BSTNode* right; //< right sub-tree
  BSTNode* parent; //< parent of this node

  BSTNode(T init_data) :
    data(init_data),
    left(nullptr),
    right(nullptr),
    parent(nullptr)
  {
  }
};

template<typename T>
/*! \brief Binary Search Tree
 * Known issues of this implementaion:
 * 1) This BST does not support duplicate values, namely each value
 *     in the tree is unique.
 *
 *    **To solve this, create a function to find the lowest node with
 *     required value**
 *
 * 2) This BST does not do balancing. So every time an item is deleted
 *     from the tree, it will be substitued by its successor (the smallest
 *     value in its right sub-tree), keep doing this can lead to an
 *     unbalanced tree.
 *
 *    **To solve this, we can randomly choose to use its successor or
 *    predecessor**
 *
 */
struct BSTree {

  BSTNode<T>* root; //< root pointer of BST tree

public:

  BSTree() : root(nullptr)
  {
  }

  //! Check if BST is empty
  bool empty()
  {
    return root == nullptr;
  }

  //! Find node with given value
  /*!
   * \param target a value to search for
   */
  BSTNode<T>* lookup(T target)
  {

    BSTNode<T>* nodePtr = root;
    while (nodePtr != nullptr) {

      if (nodePtr->data == target) return nodePtr;

      if (nodePtr->data > target) { // Search left subtree
        nodePtr= nodePtr->left;
      } else { // Search right subtree
        nodePtr = nodePtr->right;
      }
    }

    return nullptr;
  }

  //! Insert node
  BSTNode<T>* insert(T data)
  {
    // Here we do not insert new node with duplicate value
    if (lookup(data) != nullptr) {
      return lookup(data);
    }

    BSTNode<T>* newNode = new BSTNode<T>(data);

    BSTNode<T>* nodePtr= root;

    if (nodePtr == nullptr) {
      root = newNode;
      return root;
    }

    while(nodePtr != nullptr) {
      if (nodePtr->data > newNode->data) {
        if (nodePtr->left == nullptr) { // reach leaf, save new node
          nodePtr->left = newNode;
          newNode->parent = nodePtr;
          return newNode;
        }
        nodePtr = nodePtr->left; // keep searching
      } else {
        if (nodePtr->right == nullptr) { // reach leaf, save new node
          nodePtr->right = newNode;
          newNode->parent = nodePtr;
          return newNode;
        }
        nodePtr = nodePtr->right; // keep searching
      }
    }

    // should not reach here
    delete newNode;
    return nullptr;
  }

  bool remove(BSTNode<T>* nodePtr)
  {
    assert(nodePtr != nullptr);

    // Do not have any child
    if (nodePtr->left == nullptr && nodePtr->right == nullptr) {

      if(nodePtr->parent == nullptr) { // this is root
        root = nullptr;
      } else {
        // Clear parent
        if(nodePtr->parent->left == nodePtr) {
          nodePtr->parent->left = nullptr;
        } else {
          nodePtr->parent->right = nullptr;
        }
      }

      delete nodePtr;
      return true;

    } else {

      // have two children
      if (nodePtr->left != nullptr && nodePtr->right != nullptr) {
        BSTNode<T>* min_node = find_min(nodePtr); // Find minimum value
        nodePtr->data = min_node->data; // Replace value by min_node
        return remove(min_node); // remove original node

      } else {
        // have only one child

        if (nodePtr->parent == nullptr) { // nodePtr is the root
          root = nodePtr->left == nullptr ? nodePtr->right : nodePtr->left;
        } else {
          if(nodePtr->parent->left == nodePtr) {
            nodePtr->parent->left = nodePtr->left ==
                                    nullptr ? nodePtr->right : nodePtr->left;
          }

          if(nodePtr->parent->right == nodePtr) {
            nodePtr->parent->right = nodePtr->left ==
                                     nullptr ? nodePtr->right : nodePtr->left;

          }
        }


        delete nodePtr;
        return true;
      }

    }

  }

  //!Remove a value from BSTree
  bool remove(T data)
  {
    return remove(lookup(data));
  }

private:

  //! Find node with minimum value in given subtree
  //\param nodePtr root of subtree will search on
  BSTNode<T>* find_min(BSTNode<T>* nodePtr)
  {
    if (nodePtr->left != nullptr) { // has lower value in this tree
      return find_min(nodePtr->left);
    } else { // nodePtr is the smallest one, return it
      return nodePtr;
    }
  }

};

#endif
