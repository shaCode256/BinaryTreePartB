#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <set>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>	 // std::cout
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
			shared_ptr<Node> right_son;
			shared_ptr<Node> left_son;
		};

		static inline std::vector<struct shared_ptr<Node>> nodesTraverseVector;

	public:
		shared_ptr<Node> root = make_shared<Node>();
		shared_ptr<Node> iterNode = root;

		static inline void fillVectorPostorder(struct shared_ptr<Node> node)
		{
			if (node == nullptr)
				return;

			fillVectorPostorder(node->left_son);

			fillVectorPostorder(node->right_son);

			nodesTraverseVector.push_back(node);
		}

		static inline void fillVectorInorder(struct shared_ptr<Node> node)
		{
			if (node == nullptr)
				return;

			fillVectorInorder(node->left_son);

			nodesTraverseVector.push_back(node);

			fillVectorInorder(node->right_son);
		}

		static void inline fillVectorPreorder(struct shared_ptr<Node> node)
		{
			if (node == nullptr)
				return;

			nodesTraverseVector.push_back(node);

			fillVectorPreorder(node->left_son);

			fillVectorPreorder(node->right_son);
		}

		// pre_order_iterator inner class:
		class pre_order_iterator
		{
		private:
			shared_ptr<Node> curr_node_ptr;
			shared_ptr<Node> recursive_traversal_ptr;

		public:
			pre_order_iterator(shared_ptr<Node> ptr = nullptr) : curr_node_ptr(ptr)
			{
				nodesTraverseVector.clear();
				fillVectorPreorder(ptr);
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
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
				return *this;
			}

			// i++;
			const pre_order_iterator operator++(int)
			{
				pre_order_iterator tmp = *this;
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
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
			shared_ptr<Node> curr_node_ptr;
			shared_ptr<Node> recursive_traversal_ptr;

		public:
			in_order_iterator(shared_ptr<Node> ptr = nullptr) : curr_node_ptr(ptr)
			{
				nodesTraverseVector.clear();
				fillVectorInorder(ptr);
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
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
				return *this;
			}

			// i++;
			const in_order_iterator operator++(int)
			{
				in_order_iterator tmp = *this;
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
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
			shared_ptr<Node> curr_node_ptr;
			shared_ptr<Node> recursive_traversal_ptr;

		public:
			post_order_iterator(shared_ptr<Node> ptr = nullptr) : curr_node_ptr(ptr)
			{
				nodesTraverseVector.clear();
				fillVectorPostorder(ptr);
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
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
				return *this;
			}
			// i++;
			const post_order_iterator operator++(int)
			{
				post_order_iterator tmp = *this;
				curr_node_ptr = nodesTraverseVector.front();
				nodesTraverseVector.erase(nodesTraverseVector.begin()); //delete it from the travese vector
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

	public:
		BinaryTree() : root(){};
		friend std::ostream &operator<<(std::ostream &outStream, BinaryTree &bTree)
		{
			return outStream;
		}
		std::map<int, int> example;
		BinaryTree &add_root(T rootAdd)
		{
			if (root == nullptr)
			{
				root = make_shared<Node>(); // added this line
				root->value = rootAdd;
				root->right_son = nullptr;
				root->left_son = nullptr;
			}
			//std::cout << "TheRoot" << root << "\n";
			// shared_ptr<Node>root= make_shared<Node>;
			// root->value=rootAdd;
			return *this;
		}; //- מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
		BinaryTree &add_left(T exist, T toAddLeft)
		{
			if (root == nullptr)
			{
				std::cout << "tree is empty \n";
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
			}
			shared_ptr<Node> nodeFound= ifNodeExists(root, exist);
			if (nodeFound != nullptr)
			{
				// std::cout << "found!";
				nodeFound->left_son = make_shared<Node>();
				nodeFound->left_son->value = toAddLeft;
				nodeFound->left_son->left_son = nullptr;
				nodeFound->left_son->right_son = nullptr;
			}
			else
			{	// element wasn't found
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
				//std::cout << "HEY" <<toAddLeft;
			}
			return *this;
		}; //- מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו).
		BinaryTree add_right(T exist, T toAddRight)
		{
			if (root == nullptr)
			{
				std::cout << "tree is empty \n";
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
			}
			shared_ptr<Node> nodeFound= ifNodeExists(root, exist);
			if (nodeFound != nullptr)
			{
				// std::cout << "found!";
				nodeFound->right_son = make_shared<Node>();
				nodeFound->right_son->value = toAddRight;
				nodeFound->right_son->left_son = nullptr;
				nodeFound->right_son->right_son = nullptr;
			}
			else
			{	// element wasn't found
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
				//std::cout << "HEY" <<toAddLeft;
			}
			return *this;
		}; //- כנ"ל, רק שהתוספת היא בתור הילד הימני.
		pre_order_iterator begin()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			//iterNode= nullptr;
			return pre_order_iterator(iterNode);
		}
		pre_order_iterator begin_preorder()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end_preorder()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return pre_order_iterator(iterNode);
		}; // - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
		in_order_iterator begin_inorder()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return in_order_iterator(iterNode);
		};
		in_order_iterator end_inorder()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				//cout << "yup";
				iterNode = nodesTraverseVector.back();
			}
			//iterNode= nullptr;
			return in_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
		post_order_iterator begin_postorder()
		{
			// nodesTraverseVector.clear();
			// fillVectorPostorder(root);
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return post_order_iterator(iterNode);
		};
		post_order_iterator end_postorder()
		{
			iterNode= nullptr;
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			//iterNode= nullptr;
			return post_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).
		
		void print_tree()
		{
			fillVectorPostorder(root);
			for (shared_ptr<Node> &i : nodesTraverseVector)
			{
				std::cout << i->value;
			}
		}

		void printBT(const std::string &prefix, const shared_ptr<Node> node, bool isLeft)
		{
			if (node != nullptr)
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──");

				// print the value of the node
				std::cout << node->value << std::endl;

				// enter the next tree level - left and right branch
				printBT(prefix + (isLeft ? "│   " : "    "), node->left_son, true);
				printBT(prefix + (isLeft ? "│   " : "    "), node->right_son, false);
			}
		}

		void printBT(const shared_ptr<Node> node)
		{
			printBT("", node, false);
		}

		shared_ptr<Node> ifNodeExists(shared_ptr<Node> node, int key)
		{
			if (node == nullptr)
				return nullptr;

			if (node->value == key)
				return node;

			shared_ptr<Node> res1 = ifNodeExists(node->left_son, key);
			if (res1 != nullptr)
				return node;

			shared_ptr<Node> res2 = ifNodeExists(node->right_son, key);

			return res2;
		}
	}; //END OF CLASS BinaryTree

}; //END OF NAMESPACE ariel

//Reference: https://github.com/erelsgl-at-ariel/cpp-5781/tree/master/08-templates-iterators
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
// https://www.geeksforgeeks.org/search-a-node-in-binary-tree/
// https://www.geeksforgeeks.org/iterative-preorder-traversal/