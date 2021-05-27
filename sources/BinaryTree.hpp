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
		};

		static inline std::vector<struct Node *> nodesTraverseVector;

	public:
		Node *root = new Node();
		Node *iterNode = root;

		static inline void fillVectorPostorder(struct Node *node)
		{
			if (node == nullptr)
				return;

			fillVectorPostorder(node->left_son);

			fillVectorPostorder(node->right_son);

			nodesTraverseVector.push_back(node);
		}

		static inline void fillVectorInorder(struct Node *node)
		{
			if (node == nullptr)
				return;

			fillVectorInorder(node->left_son);

			nodesTraverseVector.push_back(node);

			fillVectorInorder(node->right_son);
		}

		static void inline fillVectorPreorder(struct Node *node)
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
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;

		public:
			pre_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
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
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;

		public:
			in_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
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
			Node *curr_node_ptr;
			Node *recursive_traversal_ptr;

		public:
			post_order_iterator(Node *ptr = nullptr) : curr_node_ptr(ptr)
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
			if (root == NULL)
			{
				root = new Node; // added this line
				root->value = rootAdd;
				root->right_son = NULL;
				root->left_son = NULL;
			}
			//std::cout << "TheRoot" << root << "\n";
			// Node *root= new Node;
			// root->value=rootAdd;
			return *this;
		}; //- מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
		BinaryTree &add_left(T exist, T toAddLeft)
		{
			fillVectorPreorder(root);
			bool found = false;
			Node *nodeFound;
			if (nodesTraverseVector.empty())
			{
				std::cout << "tree is empty \n";
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
			}
			else
			{
				for (Node *i : nodesTraverseVector)
				{
					if (i->value == exist)
					{
						found = true;
						nodeFound = i;
						break;
					}
					//std::cout << "THIS" << i->value;
				}
			}
			if (found == true)
			{
				// std::cout << "found!";
				nodeFound->left_son = new Node();
				nodeFound->left_son->value = toAddLeft;
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
			fillVectorPreorder(root);
			bool found = false;
			Node *nodeFound;
			if (nodesTraverseVector.empty())
			{
				std::cout << "tree is empty \n";
				//throw std::invalid_argument ("add_left error: Element exist is not found in this tree");
			}
			else
			{
				for (Node *i : nodesTraverseVector)
				{
					if (i->value == exist)
					{
						found = true;
						nodeFound = i;
						break;
					}
					//std::cout << "THIS" << i->value;
				}
			}
			if (found == true)
			{
				// std::cout << "found!";
				nodeFound->right_son = new Node();
				nodeFound->right_son->value = toAddRight;
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
			nodesTraverseVector.clear();
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end()
		{
			nodesTraverseVector.clear();
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return pre_order_iterator(iterNode);
		}
		pre_order_iterator begin_preorder()
		{
			nodesTraverseVector.clear();
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end_preorder()
		{
			nodesTraverseVector.clear();
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return pre_order_iterator(iterNode);
		}; // - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
		in_order_iterator begin_inorder()
		{
			nodesTraverseVector.clear();
			fillVectorInorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return in_order_iterator(iterNode);
		};
		in_order_iterator end_inorder()
		{
			nodesTraverseVector.clear();
			fillVectorInorder(root);
			if (!nodesTraverseVector.empty())
			{
				//cout << "yup";
				iterNode = nodesTraverseVector.back();
			}
			return in_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
		post_order_iterator begin_postorder()
		{
			nodesTraverseVector.clear();
			fillVectorPostorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return post_order_iterator(iterNode);
		};
		post_order_iterator end_postorder()
		{
			nodesTraverseVector.clear();
			fillVectorPostorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return post_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).
		void print_tree()
		{
			fillVectorPostorder(root);
			for (Node *&i : nodesTraverseVector)
			{
				std::cout << i->value;
			}
		}

		void printBT(const std::string &prefix, const Node *node, bool isLeft)
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

		void printBT(const Node *node)
		{
			printBT("", node, false);
		}

	}; //END OF CLASS BinaryTree

}; //END OF NAMESPACE ariel

//Reference: https://github.com/erelsgl-at-ariel/cpp-5781/tree/master/08-templates-iterators
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c