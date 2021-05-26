/* 

 *
 * TEST FOR BinaryTree.CPP
 *
 * AUTHOR: Shavit Luzon
 *
 * Date: 2021-05
 *

*/

#include "BinaryTree.hpp"
#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "doctest.h"
#include <string>
#include <sstream>

// using namespace std;
using namespace ariel;

/* 
  Functions to check: all operations.
 */

TEST_CASE("Checking the demo works as expected")
{

  std::ostringstream stream;
  std::string str;
  std::cout << "hey! you're in my test \n";
  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

  std::cout << tree_of_ints << std::endl; /* Prints the tree in a reasonable format. For example:
        1
        |--------|
        2        3
        |---|
        4   5
  */

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();
  CHECK_EQ(str, "1 2 4 5 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();
  CHECK_EQ(str, "4 2 5 1 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();
  CHECK_EQ(str, "4 5 2 3 1");

  stream.str("");
  stream.clear();
  for (int element : tree_of_ints)
  { // this should work like inorder
    stream << element << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  // The same should work with other types, e.g. with strings:

  BinaryTree<std::string> tree_of_strings;
  tree_of_strings.add_root("1")
      .add_left("1", "9")  // Now 9 is the left child of 1
      .add_left("9", "4")  // Now 4 is the left child of 9
      .add_right("9", "5") // Now 5 is the right child of 9
      .add_right("1", "3") // Now 3 is the right child of 1
      .add_left("1", "2"); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  std::cout << tree_of_strings << std::endl;

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_preorder(); it != tree_of_strings.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();

  CHECK_EQ(str, "1 2 4 5 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_inorder(); it != tree_of_strings.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();

  CHECK_EQ(str, "4 5 2 3 1");

  // demonstrate the arrow operator:

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it)
  {
    stream << it->size() << " ";
  } // prints: 1 1 1 1 1
  str = stream.str();

  CHECK_EQ(str, "1 1 1 1 1");

  ////////////////////REPEATING THIS JUST TO SEE THERE WAS NO CHANGES

  BinaryTree<int> tree_of_ints_2;
  tree_of_ints_2.add_root(1)
      .add_left(1, 9)  // Now 9 is the left child of 1
      .add_left(9, 4)  // Now 4 is the left child of 9
      .add_right(9, 5) // Now 5 is the right child of 9
      .add_right(1, 3) // Now 3 is the right child of 1
      .add_left(1, 2); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

  std::cout << tree_of_ints_2 << std::endl; /* Prints the tree in a reasonable format. For example:
        1
        |--------|
        2        3
        |---|
        4   5
  */

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints_2.begin_preorder(); it != tree_of_ints_2.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();

  CHECK_EQ(str, "1 2 4 5 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints_2.begin_inorder(); it != tree_of_ints_2.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_ints_2.begin_postorder(); it != tree_of_ints_2.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();

  CHECK_EQ(str, "4 5 2 3 1");

  stream.str("");
  stream.clear();
  for (int element : tree_of_ints_2)
  { // this should work like inorder
    stream << element << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  // The same should work with other types, e.g. with strings:

  BinaryTree<std::string> tree_of_strings_2;
  tree_of_strings_2.add_root("1")
      .add_left("1", "9")  // Now 9 is the left child of 1
      .add_left("9", "4")  // Now 4 is the left child of 9
      .add_right("9", "5") // Now 5 is the right child of 9
      .add_right("1", "3") // Now 3 is the right child of 1
      .add_left("1", "2"); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  std::cout << tree_of_strings_2 << std::endl;

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_preorder(); it != tree_of_strings_2.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();

  CHECK_EQ(str, "1 2 4 5 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_inorder(); it != tree_of_strings_2.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_postorder(); it != tree_of_strings_2.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();

  CHECK_EQ(str, "4 5 2 3 1");

  stream.str("");
  stream.clear();
  // demonstrate the arrow operator:
  for (auto it = tree_of_strings_2.begin_postorder(); it != tree_of_strings_2.end_postorder(); ++it)
  {
    stream << it->size() << " ";
  } // prints: 1 1 1 1 1
  str = stream.str();

  CHECK_EQ(str, "1 1 1 1 1");

  //And again 4 last tests:

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_preorder(); it != tree_of_strings_2.end_preorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 1 2 4 5 3
  str = stream.str();

  CHECK_EQ(str, "1 2 4 5 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_inorder(); it != tree_of_strings_2.end_inorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 2 5 1 3
  str = stream.str();

  CHECK_EQ(str, "4 2 5 1 3");

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_postorder(); it != tree_of_strings_2.end_postorder(); ++it)
  {
    stream << (*it) << " ";
  } // prints: 4 5 2 3 1
  str = stream.str();

  CHECK_EQ(str, "4 5 2 3 1");

  // demonstrate the arrow operator:

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_postorder(); it != tree_of_strings_2.end_postorder(); ++it)
  {
    stream << it->size() << " ";
  } // prints: 1 1 1 1 1
  str = stream.str();

  CHECK_EQ(str, "1 1 1 1 1");

  // demonstrate the arrow operator:

  stream.str("");
  stream.clear();
  for (auto it = tree_of_strings_2.begin_postorder(); it != tree_of_strings_2.end_postorder(); ++it)
  {
    stream << it->size() << " ";
  } // prints: 1 1 1 1 1
  str = stream.str();

  CHECK_EQ(str, "1 1 1 1 1");

} //ENDED test case

//Reference: 
//https://stackoverflow.com/questions/3513173/converting-ostream-into-standard-string
//https://stackoverflow.com/questions/5781597/incomplete-type-is-not-allowed-stringstream/5781612
//https://stackoverflow.com/questions/5288036/how-to-clear-ostringstream