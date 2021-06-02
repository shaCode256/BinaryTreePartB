#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <set>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>  // std::cout
#include <algorithm> // std::find
#include <iterator>
#include <memory>

using namespace std;

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
        // inner class Node
        struct Node
        {
            T value;
            Node *right_son;
            Node *left_son;
            Node *parent;
            Node(const T &val) : value(val), right_son(nullptr), left_son(nullptr), parent(nullptr) {}
        };

    public:
        Node *root;
        Node *iterNode;

        // pre_order_iterator inner class:
        class pre_order_iterator
        {
        private:
            Node *curr_node_ptr;
            Node *recursive_traversal_ptr;

        public:
            Node *preorderSuccessor(Node *n)
            {
                //a bug fix for the successor
                if (n->left_son == nullptr && n->right_son != nullptr)
                {
                    return n->right_son;
                }
                if (n->left_son != nullptr)
                {
                    return n->left_son;
                }
                Node *curr = n;
                Node *parent = curr->parent;
                while (parent != nullptr && parent->right_son == curr)
                {
                    curr = curr->parent;
                    parent = parent->parent;
                }
                if (parent == nullptr)
                {
                    return nullptr;
                }
                return parent->right_son;
            }

            pre_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
            {
                curr_node_ptr = ptr;
            };

            T &operator*() const
            {
                return curr_node_ptr->value;
            }

            T *operator->() const
            {
                return &(curr_node_ptr->value);
            }

            // ++i;
            pre_order_iterator &operator++()
            {
                Node *curr = curr_node_ptr;
                Node *parent = curr_node_ptr->parent;
                curr_node_ptr = preorderSuccessor(curr_node_ptr);
                return *this;
            }

            // i++;
            pre_order_iterator operator++(int)
            {
                pre_order_iterator tmp = *this;
                curr_node_ptr = preorderSuccessor(curr_node_ptr);
                return tmp;
            }

            bool operator==(const pre_order_iterator &rhs) const
            {
                return curr_node_ptr == rhs.curr_node_ptr;
            }

            bool operator!=(const pre_order_iterator &rhs) const
            {
                return curr_node_ptr != rhs.curr_node_ptr;
            }
        }; // END OF CLASS pre_order_iterator

        class in_order_iterator
        {
        private:
            Node *curr_node_ptr;
            Node *recursive_traversal_ptr;

        public:
            Node *inorderSuccessor(Node *node)
            {
                if (node->right_son)
                {
                    node = node->right_son;
                    while (node->left_son)
                    {
                        node = node->left_son;
                    }
                    return node;
                }
                while (node->parent && node != node->parent->left_son)
                {
                    node = node->parent;
                }
                return node->parent;
            }

            in_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
            {
                curr_node_ptr = ptr;
            };

            T &operator*() const
            {
                return curr_node_ptr->value;
            }

            T *operator->() const
            {
                return &(curr_node_ptr->value);
            }

            // ++i;
            in_order_iterator &operator++()
            {
                curr_node_ptr = inorderSuccessor(curr_node_ptr);
                return *this;
            }

            // i++;
            in_order_iterator operator++(int)
            {
                in_order_iterator tmp = *this;
                curr_node_ptr = inorderSuccessor(curr_node_ptr);
                return tmp;
            }

            bool operator==(const in_order_iterator &rhs) const
            {
                return curr_node_ptr == rhs.curr_node_ptr;
            }

            bool operator!=(const in_order_iterator &rhs) const
            {
                return curr_node_ptr != rhs.curr_node_ptr;
            }
        }; // END OF CLASS in_order_iterator

        class post_order_iterator
        {
        private:
            Node *curr_node_ptr;
            Node *recursive_traversal_ptr;

        public:
            Node *postorderSuccessor(Node *n)
            {
                if (n->parent == nullptr)
                { //means it's the root
                    return nullptr;
                }
                Node *parent = n->parent;
                if (parent->right_son == nullptr || parent->right_son == n)
                {
                    return parent;
                }
                Node *curr = parent->right_son;
                while (curr->left_son != nullptr)
                {
                    curr = curr->left_son;
                }
                return curr;
            }

            post_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
            {
                curr_node_ptr = ptr;
            };

            T &operator*() const
            {
                return curr_node_ptr->value;
            }

            T *operator->() const
            {
                return &(curr_node_ptr->value);
            }

            // ++i;
            post_order_iterator &operator++()
            {
                curr_node_ptr = postorderSuccessor(curr_node_ptr);
                return *this;
            }
            // i++;
            post_order_iterator operator++(int)
            {
                post_order_iterator tmp = *this;
                curr_node_ptr = postorderSuccessor(curr_node_ptr);
                return tmp;
            }

            bool operator==(const post_order_iterator &rhs) const
            {
                return curr_node_ptr == rhs.curr_node_ptr;
            }

            bool operator!=(const post_order_iterator &rhs) const
            {
                return curr_node_ptr != rhs.curr_node_ptr;
            }
        }; // END OF CLASS post_order_iterator

        //Node rootNode();

        BinaryTree()
        {
            root = nullptr;
        };

        void delete_tree(Node *node)
        {
            // if (node == NULL){
            //     return;
            // }
            // delete_tree(node->left_son);
            // delete_tree(node->right_son);
            // delete node;
        }

        ~BinaryTree()
        {
            delete_tree(root);
        };

        BinaryTree(BinaryTree &&other) noexcept
        {
            // Move constructor
            // It will simply shift the resources,
            // without creating a copy.
            //cout << "Calling Move constructor\n";
            this->root = other.root;
            other.root = NULL;
        }

        // Move assignment operator.
        BinaryTree &operator=(BinaryTree &&other) noexcept
        {
            if (this != &other)
            {
                // // Free the existing resource.
                // delete[] _data;

                // // Copy the data pointer and its length from the
                // // source object.
                // _data = other._data;
                // _length = other._length;

                // // Release the data pointer from the source object so that
                // // the destructor does not free the memory multiple times.
                // other._data = nullptr;
                // other._length = 0;
            }
            return *this;
        }

        //Deep Copy constructor
        BinaryTree &operator=(BinaryTree other)
        {
            cout << "huh";
            return *this;
        }

        //coping the nodes of the tree by preorder traversal
        // void copyTree(Node* root)
        // {
        //     if (root == nullptr)
        //     {
        //         return;
        //     }
        //     Node newNode = Node(root->value);
        //     newNode.left_son = copyTree(root->left_son);
        //     newNode.right_son = copyTree(root->right_son);
        // }

        //Move constructor
        BinaryTree(BinaryTree &other)
        {
            root = other.root;
        }

        std::map<int, int> example;
        BinaryTree &add_root(T rootAdd)
        {
            if (root == nullptr)
            {
                root = new Node(rootAdd); // added this line
            }
            else{
                root->value= rootAdd;
            }
            //std::cout << "TheRoot" << root << "\n";
            // Node*root= make_shared<Node>;
            // root->value=rootAdd;
            return *this;
        }; //- מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
        BinaryTree &add_left(T exist, T toAddLeft)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument("ROOT IS NULL. add_left error: Element exist is not found in this tree");
            }
            Node *nodeFound = ifNodeExists(root, exist);
            if (nodeFound != nullptr)
            {
                if (nodeFound->left_son == nullptr)
                {
                    nodeFound->left_son = new Node(toAddLeft);
                    nodeFound->left_son->parent = nodeFound;
                }
                else
                {
                    if(nodeFound->left_son->value== toAddLeft){
                        throw std::invalid_argument("add_left error: Element with this value alreay exists in that position");
                    }
                    nodeFound->left_son->value = toAddLeft;
                }
            }
            else
            { // element wasn't found
                throw std::invalid_argument("add_left error: Element exist is not found in this tree");
                //std::cout << "HEY" <<toAddLeft;
            }
            return *this;
        }; //- מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו).
        BinaryTree add_right(T exist, T toAddRight)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument("Tree is empty: add_left error: Element exist is not found in this tree");
            }
            Node *nodeFound = ifNodeExists(root, exist);
            if (nodeFound != nullptr)
            {
                // std::cout << "found!";
                if (nodeFound->right_son == nullptr)
                {
                    nodeFound->right_son = new Node(toAddRight);
                    nodeFound->right_son->parent = nodeFound;
                }
                else
                {
                    if(nodeFound->right_son->value== toAddRight){
                        throw std::invalid_argument("add_right error: Element with this value alreay exists in that position");
                    }
                    nodeFound->right_son->value = toAddRight;
                }
            }
            else
            { // element wasn't found
                throw std::invalid_argument("add_left error: Element exist is not found in this tree");
            }
            return *this;
        }; //- כנ"ל, רק שהתוספת היא בתור הילד הימני.

        in_order_iterator begin()
        {
            return begin_inorder();
        };

        in_order_iterator end()
        {
            return end_inorder();
        }

        pre_order_iterator begin_preorder()
        {
            return pre_order_iterator(root);
        };

        pre_order_iterator end_preorder()
        {
            return pre_order_iterator(nullptr);
        }; // - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).

        in_order_iterator begin_inorder()
        {
            Node *beginNode = root;
            while (beginNode != nullptr && beginNode->left_son != nullptr)
            {
                beginNode = beginNode->left_son;
            }
            return in_order_iterator(beginNode);
        };

        in_order_iterator end_inorder()
        {
            return in_order_iterator(nullptr);
        }; //- מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).

        post_order_iterator begin_postorder()
        {
            Node *beginNode = root;
            beginNode = findFirstPostorder(root);
            return post_order_iterator(beginNode);
        };

        Node *findFirstPostorder(Node *node)
        {
            while (node != nullptr)
            {
                while (node->left_son != nullptr)
                {
                    node = node->left_son;
                }
                if (node->right_son != nullptr)
                {
                    node = node->right_son;
                }
                else
                {
                    return node;
                }
            }
            return node;
        }

        post_order_iterator end_postorder()
        {
            return post_order_iterator(nullptr);
        }; //- מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).

        // void printBT(const std::string &prefix, const Node* node, bool isLeft, std::string treeDesc)
        // {
        // 	if (node != nullptr)
        // 	{
        // 		//std::cout << prefix;
        //         treeDesc+=prefix;

        // 		//std::cout << (isLeft ? "├──" : "└──");
        //         treeDesc+= (isLeft ? "├──" : "└──");

        // 		// print the value of the node
        // 		//std::cout << node->value << std::endl;
        //         treeDesc+=  node->value += "\n";

        // 		// enter the next tree level - left and right branch
        // 		printBT(prefix + (isLeft ? "│   " : "    "), node->left_son, true);
        // 		printBT(prefix + (isLeft ? "│   " : "    "), node->right_son, false);
        // 	}
        // }

        //  friend std::ostream &operator<<(std::ostream &outStream, BinaryTree<T> &tree){
        //     std::string treeDesc;
        //     printBT(tree);
        //     return std::operator<<(outStream, treeDesc);
        // }

        friend std::ostream &operator<<(std::ostream &outStream, BinaryTree &tree)
        {
            return outStream;
        }

        Node *ifNodeExists(Node *node, T key)
        {
            if (node == nullptr)
            {
                return nullptr;
            }
            if (node->value == key)
            {
                return node;
            }
            Node *res1 = ifNodeExists(node->left_son, key);
            if (res1 != nullptr)
            {
                return res1;
            }
            Node *res2 = ifNodeExists(node->right_son, key);
            return res2;
        }

    }; //END OF CLASS BinaryTree

}; //END OF NAMESPACE ariel

//Reference:
// https://github.com/erelsgl-at-ariel/cpp-5781/tree/master/08-templates-iterators
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
// https://www.geeksforgeeks.org/search-a-node-in-binary-tree/
// https://www.geeksforgeeks.org/iterative-preorder-traversal/
// https://www.tutorialspoint.com/inorder-successor-in-bst-ii-in-cplusplus
// https://www.geeksforgeeks.org/preorder-successor-node-binary-tree/
// https://www.geeksforgeeks.org/postorder-successor-node-binary-tree/
// https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/