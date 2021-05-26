#pragma once
#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include <cassert>
#include <set>
#include <bits/stdc++.h>
#include <vector>

namespace ariel
{
	template <typename T>
	class BinaryTree
	{
		// inner class Node
		struct Node
		{
			T value;
			struct Node *right_son;
			struct Node *left_son;
			Node(const T &val)
				: value(val), left_son(nullptr), right_son(nullptr){};
			Node()
			{
			}
		};

		static inline std::vector<struct Node *> nodesTraverseVector;

	public:
		static inline void fillVectorPostorder(struct Node *node)
		{
			if (node == NULL)
				return;

			// first recur on left subtree
			fillVectorPostorder(node->left_son);

			// then recur on right subtree
			fillVectorPostorder(node->right_son);

			// now deal with the node
			nodesTraverseVector.push_back(node);
		}

		static inline void fillVectorInorder(struct Node *node)
		{
			if (node == NULL)
				return;

			/* first recur on left child */
			fillVectorInorder(node->left_son);

			/* then print the data of node */
			nodesTraverseVector.push_back(node);

			/* now recur on right child */
			fillVectorInorder(node->right_son);
		}

		static void inline fillVectorPreorder(struct Node *node)
		{
			if (node == NULL)
				return;

			/* first print data of node */
			nodesTraverseVector.push_back(node);

			/* then recur on left sutree */
			fillVectorPreorder(node);

			/* now recur on right subtree */
			fillVectorPreorder(node);
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

		int a = 0;
		Node *root;
		Node *iterNode = root;
		//Node rootNode();

	public:
		BinaryTree() : root(nullptr){};
		friend std::ostream &operator<<(std::ostream &outStream, BinaryTree &bTree)
		{
			return outStream;
		}
		std::map<int, int> example;
		BinaryTree add_root(T root)
		{
			return *this;
		}; //- מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
		BinaryTree &add_left(T exist, T toAddLeft)
		{
			return *this;
		}; //- מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו).
		BinaryTree add_right(T exist, T toAddRight)
		{
			return *this;
		}; //- כנ"ל, רק שהתוספת היא בתור הילד הימני.
		pre_order_iterator begin()
		{
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end()
		{
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return pre_order_iterator(iterNode);
		}
		pre_order_iterator begin_preorder()
		{
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return pre_order_iterator(iterNode);
		};
		pre_order_iterator end_preorder()
		{
			fillVectorPreorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return pre_order_iterator(iterNode);
		}; // - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
		in_order_iterator begin_inorder()
		{
			fillVectorInorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return in_order_iterator(iterNode);
		};
		in_order_iterator end_inorder()
		{
			fillVectorInorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return in_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
		post_order_iterator begin_postorder()
		{
			fillVectorPostorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.front();
			}
			return post_order_iterator(iterNode);
		};
		post_order_iterator end_postorder()
		{
			fillVectorPostorder(root);
			if (!nodesTraverseVector.empty())
			{
				iterNode = nodesTraverseVector.back();
			}
			return post_order_iterator(iterNode);
		}; //- מחזירות איטרטורים לצורך מעבר בסדר postorder (שמאל - ימין - אב).

	}; //END OF CLASS BinaryTree

}; //END OF NAMESPACE ariel

//Reference: https://github.com/erelsgl-at-ariel/cpp-5781/tree/master/08-templates-iterators
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/