/**
 * Author: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "complex.hpp"
#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"
using namespace std;


// Tree functions

// Add root
// Int tree
TEST_CASE("Add root to int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);


    SUBCASE("Add root to int tree") {
        binary_int_tree.add_root(int_root);
        CHECK(binary_int_tree.getRoot() == int_root);
    }
    SUBCASE("Add root to int tree that already has a root") {
        binary_int_tree.add_root(int_1);
        binary_int_tree.add_root(int_root);
        CHECK(binary_int_tree.getRoot() == int_root);
    }
}
// String tree
TEST_CASE("Add root to string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("root");
node<string>* string_1 = new node<string>("child1");


    SUBCASE("Add root to string tree") {
        binary_string_tree.add_root(string_root);
        CHECK(binary_string_tree.getRoot() == string_root);
    }
    SUBCASE("Add root to string tree that already has a root") {
        binary_string_tree.add_root(string_1);
        binary_string_tree.add_root(string_root);
        CHECK(binary_string_tree.getRoot() == string_root);
    }
}
// Complex tree
TEST_CASE("Add root to complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));


    SUBCASE("Add root to complex tree") {
        binary_complex_tree.add_root(complex_root);
        CHECK(binary_complex_tree.getRoot() == complex_root);
    }
    SUBCASE("Add root to complex tree that already has a root") {
        binary_complex_tree.add_root(complex_1);
        binary_complex_tree.add_root(complex_root);
        CHECK(binary_complex_tree.getRoot() == complex_root);
    }
}
// Unary tree
TEST_CASE("Add root to unary tree") {
    tree<int, 1> unary_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);

    SUBCASE("Add root to unary tree") {
        unary_tree.add_root(int_root);
        CHECK(unary_tree.getRoot() == int_root);
    }
    SUBCASE("Add root to unary tree that already has a root") {
        unary_tree.add_root(int_1);
        unary_tree.add_root(int_root);
        CHECK(unary_tree.getRoot() == int_root);
    }
}
// Quad tree
TEST_CASE("Add root to quad tree") {
    tree<int, 4> quad_tree;
     node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);

    SUBCASE("Add root to quad tree") {
        quad_tree.add_root(int_root);
        CHECK(quad_tree.getRoot() == int_root);
    }
    SUBCASE("Add root to quad tree that already has a root") {
        quad_tree.add_root(int_1);
        quad_tree.add_root(int_root);
        CHECK(quad_tree.getRoot() == int_root);
    }
}
// Ten tree
TEST_CASE("Add root to ten tree") {
    tree<int, 10> ten_tree;
      node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);

    SUBCASE("Add root to ten tree") {
        ten_tree.add_root(int_root);
        CHECK(ten_tree.getRoot() == int_root);
    }
    SUBCASE("Add root to ten tree that already has a root") {
        ten_tree.add_root(int_1);
        ten_tree.add_root(int_root);
        CHECK(ten_tree.getRoot() == int_root);
    }
}

// Add sub node
// Int tree
TEST_CASE("Add sub node to int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);

    SUBCASE("Add sub node to root") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        CHECK(int_root->getChildren().at(0) == int_1);
    }
    SUBCASE("Add sub node to node") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        CHECK(int_1->getChildren().at(0) == int_3);
        CHECK(int_1->getChildren().at(1) == int_4);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        CHECK(binary_int_tree.add_sub_node(int_1, int_5) == false);
    }
}
// String tree
TEST_CASE("Add sub node to string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("root");
node<string>* string_1 = new node<string>("child1");
node<string>* string_2 = new node<string>("child2");
node<string>* string_3 = new node<string>("child3");
node<string>* string_4 = new node<string>("child4");
node<string>* string_5 = new node<string>("child5");

    SUBCASE("Add sub node to root") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        CHECK(string_root->getChildren().at(0) == string_1);
    }
    SUBCASE("Add sub node to node") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        CHECK(string_1->getChildren().at(0) == string_3);
        CHECK(string_1->getChildren().at(1) == string_4);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        CHECK(binary_string_tree.add_sub_node(string_1, string_5) == false);
    }
}
// Complex tree
TEST_CASE("Add sub node to complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));
node<Complex>* complex_2 = new node<Complex>(Complex(5, 0));
node<Complex>* complex_3 = new node<Complex>(Complex(0, -5));
node<Complex>* complex_4 = new node<Complex>(Complex(0, 0));
node<Complex>* complex_5 = new node<Complex>(Complex(0, 0));

    SUBCASE("Add sub node to root") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        CHECK(complex_root->getChildren().at(0) == complex_1);
    }
    SUBCASE("Add sub node to node") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        CHECK(complex_1->getChildren().at(0) == complex_3);
        CHECK(complex_1->getChildren().at(1) == complex_4);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        CHECK(binary_complex_tree.add_sub_node(complex_1, complex_5) == false);
    }
}
// Unary tree
TEST_CASE("Add sub node to unary tree") {
    tree<int, 1> unary_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
   
    SUBCASE("Add sub node to root") {
        unary_tree.add_root(int_root);
        unary_tree.add_sub_node(int_root, int_1);
        CHECK(int_root->getChildren().at(0) == int_1);
    }
    SUBCASE("Add sub node to node") {
        unary_tree.add_root(int_root);
        unary_tree.add_sub_node(int_root, int_1);
        unary_tree.add_sub_node(int_1, int_2);
        unary_tree.add_sub_node(int_2, int_3);
        CHECK(int_2->getChildren().at(0) == int_3);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        unary_tree.add_root(int_root);
        unary_tree.add_sub_node(int_root, int_1);
        unary_tree.add_sub_node(int_1, int_2);
        unary_tree.add_sub_node(int_2, int_3);
        CHECK(unary_tree.add_sub_node(int_2, int_4) == false);
    }
}
// Quad tree
TEST_CASE("Add sub node to quad tree") {
    tree<int, 4> quad_tree;
     node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);

    SUBCASE("Add sub node to root") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        CHECK(int_root->getChildren().at(0) == int_1);
    }
    SUBCASE("Add sub node to node") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        CHECK(int_1->getChildren().at(0) == int_5);
        CHECK(int_root->getChildren().at(0) == int_1);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        CHECK(quad_tree.add_sub_node(int_1, int_9) == false);
    }
}
// Ten tree
TEST_CASE("Add sub node to ten tree") {
    tree<int, 10> ten_tree;
      node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    SUBCASE("Add sub node to root") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        CHECK(int_root->getChildren().at(0) == int_1);
    }
    SUBCASE("Add sub node to node") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        CHECK(int_1->getChildren().at(0) == int_5);
        CHECK(int_1->getChildren().at(9) == int_14);
    }
    SUBCASE("Add sub node to node that has maximum number of children") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        CHECK(ten_tree.add_sub_node(int_1, int_15) == false);
    }
}

// Iterators functions

// index_iterator
// Int tree
TEST_CASE("index_iterator for int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
   
    SUBCASE("Pre order") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_index_iterator(0);
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 10; i++) {
            ++it;
        }
        CHECK(*it == 12);
        ++it;
        ++it;
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(it == binary_int_tree.end_index_iterator());
    }
    SUBCASE("In order") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_index_iterator(1);
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 3);
        for (int i = 0; i < 10; i++) {
            ++it;
        }
        CHECK(*it == 2);
        ++it;
        ++it;
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(it == binary_int_tree.end_index_iterator());
    }
    SUBCASE("Post order") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_index_iterator(2);
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 8);
        for (int i = 0; i < 10; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        ++it;
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(it == binary_int_tree.end_index_iterator());
    }
    SUBCASE("Invalid index") {
        binary_int_tree.add_root(int_root);
        CHECK_THROWS(binary_int_tree.begin_index_iterator(3));
    }
}
// String tree
TEST_CASE("index_iterator for string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("root");
node<string>* string_1 = new node<string>("child1");
node<string>* string_2 = new node<string>("child2");
node<string>* string_3 = new node<string>("child3");
node<string>* string_4 = new node<string>("child4");
node<string>* string_5 = new node<string>("child5");
node<string>* string_6 = new node<string>("child6");
node<string>* string_7 = new node<string>("child7");
    SUBCASE("Pre order") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_index_iterator(0);
        CHECK(*it == "root");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child5");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_index_iterator());
    }
    SUBCASE("In order") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_index_iterator(1);
        CHECK(*it == "child7");
        ++it;
        CHECK(*it == "child3");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child2");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_index_iterator());
    }
    SUBCASE("Post order") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_index_iterator(2);
        CHECK(*it == "child7");
        ++it;
        CHECK(*it == "child3");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child2");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_index_iterator());
    }
}
// Complex tree
TEST_CASE("index_iterator for complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));
node<Complex>* complex_2 = new node<Complex>(Complex(5, 0));
node<Complex>* complex_3 = new node<Complex>(Complex(0, -5));
node<Complex>* complex_4 = new node<Complex>(Complex(0, 0));
node<Complex>* complex_5 = new node<Complex>(Complex(0, 0));

    SUBCASE("Pre order") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_index_iterator(0);
        CHECK(*it == Complex(1, 2));
        ++it;
        CHECK(*it == Complex(3, 4));
        ++it;
        ++it;
        CHECK(*it == Complex(0, 0));
       
    }
    SUBCASE("In order") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_index_iterator(1);
        CHECK(*it == Complex(0, -5));
        ++it;
        CHECK(*it == Complex(3, 4));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(1, 2));
       
    }
    SUBCASE("Post order") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_index_iterator(2);
        CHECK(*it == Complex(0, -5));
        ++it;
        CHECK(*it == Complex(0, 0));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(0, 0));
       
    }
}
// Unary tree
TEST_CASE("index_iterator for unary tree") {
    tree<int, 1> unary_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    
    SUBCASE("Pre order") {
        unary_tree.add_root(int_root);
        unary_tree.add_sub_node(int_root, int_1);
        unary_tree.add_sub_node(int_1, int_2);
        unary_tree.add_sub_node(int_2, int_3);
        unary_tree.add_sub_node(int_3, int_4);
        unary_tree.add_sub_node(int_4, int_5);
        unary_tree.add_sub_node(int_5, int_6);
        unary_tree.add_sub_node(int_6, int_7);
        unary_tree.add_sub_node(int_7, int_8);
        unary_tree.add_sub_node(int_8, int_9);
        unary_tree.add_sub_node(int_9, int_10);
        unary_tree.add_sub_node(int_10, int_11);
        unary_tree.add_sub_node(int_11, int_12);
        unary_tree.add_sub_node(int_12, int_13);
        unary_tree.add_sub_node(int_13, int_14);

        auto it = unary_tree.begin_index_iterator(0);
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 13; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        ++it;
        CHECK(it == unary_tree.end_index_iterator());
    }
    SUBCASE("In order/Post order") {
        unary_tree.add_root(int_root);
        unary_tree.add_sub_node(int_root, int_1);
        unary_tree.add_sub_node(int_1, int_2);
        unary_tree.add_sub_node(int_2, int_3);
        unary_tree.add_sub_node(int_3, int_4);
        unary_tree.add_sub_node(int_4, int_5);
        unary_tree.add_sub_node(int_5, int_6);
        unary_tree.add_sub_node(int_6, int_7);
        unary_tree.add_sub_node(int_7, int_8);
        unary_tree.add_sub_node(int_8, int_9);
        unary_tree.add_sub_node(int_9, int_10);
        unary_tree.add_sub_node(int_10, int_11);
        unary_tree.add_sub_node(int_11, int_12);
        unary_tree.add_sub_node(int_12, int_13);
        unary_tree.add_sub_node(int_13, int_14);

        auto it = unary_tree.begin_index_iterator(1);
        CHECK(*it == 14);
        ++it;
        CHECK(*it == 13);
        for (int i = 0; i < 13; i++) {
            ++it;
        }
        CHECK(*it == 0);
        ++it;
        ++it;
        CHECK(it == unary_tree.end_index_iterator());
    }
    SUBCASE("Invalid index") {
        unary_tree.add_root(int_root);
        CHECK_THROWS(unary_tree.begin_index_iterator(2));
    }
}
// Quad tree
TEST_CASE("index_iterator for quad tree") {
    tree<int, 4> quad_tree;
     node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Pre order") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_2, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_3, int_15);
        quad_tree.add_sub_node(int_3, int_16);

        auto it = quad_tree.begin_index_iterator(0);
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
        ++it;
        CHECK(it == quad_tree.end_index_iterator());
    }
    SUBCASE("In order") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_3, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_4, int_15);
        quad_tree.add_sub_node(int_4, int_16);

        auto it = quad_tree.begin_index_iterator(2);
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 6);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
        ++it;
        CHECK(it == quad_tree.end_index_iterator());
    }
    SUBCASE("Post order") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_3, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_4, int_15);
        quad_tree.add_sub_node(int_4, int_16);

        auto it = quad_tree.begin_index_iterator(4);
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 6);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 0);
        ++it;
        ++it;
        CHECK(it == quad_tree.end_index_iterator());
    }
    SUBCASE("Invalid index") {
        quad_tree.add_root(int_root);
        CHECK_THROWS(quad_tree.begin_index_iterator(6));
    }
}
// Ten tree
TEST_CASE("index_iterator for ten tree") {
    tree<int, 10> ten_tree;
      node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Pre order") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        ten_tree.add_sub_node(int_5, int_15);
        ten_tree.add_sub_node(int_5, int_16);

        auto it = ten_tree.begin_index_iterator(0);
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
        ++it;
        CHECK(it == ten_tree.end_index_iterator());
    }
    SUBCASE("In order") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        ten_tree.add_sub_node(int_5, int_15);
        ten_tree.add_sub_node(int_5, int_16);

        auto it = ten_tree.begin_index_iterator(5);
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 16);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 0);
        ++it;
        ++it;
        CHECK(it == ten_tree.end_index_iterator());
    }
    SUBCASE("Post order") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        ten_tree.add_sub_node(int_5, int_15);
        ten_tree.add_sub_node(int_5, int_16);

        auto it = ten_tree.begin_index_iterator(10);
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 16);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 0);
        ++it;
        ++it;
        CHECK(it == ten_tree.end_index_iterator());
    }
    SUBCASE("Invalid index") {
        ten_tree.add_root(int_root);
        CHECK_THROWS(ten_tree.begin_index_iterator(17));
    }
}

// bfs_iterator
// Int tree
TEST_CASE("bfs_iterator for int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
   
    SUBCASE("Hole tree") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 13; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        CHECK(it == binary_int_tree.end_bfs_scan());
    }
    SUBCASE("Partial tree") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_3, int_6);
        binary_int_tree.add_sub_node(int_6, int_7);
        binary_int_tree.add_sub_node(int_6, int_8);
        binary_int_tree.add_sub_node(int_7, int_9);

        auto it = binary_int_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == 7);
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == 9);
        ++it;
        CHECK(it == binary_int_tree.end_bfs_scan());
    }
}
// String tree
TEST_CASE("bfs_iterator for string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("root");
node<string>* string_1 = new node<string>("child1");
node<string>* string_2 = new node<string>("child2");
node<string>* string_3 = new node<string>("child3");
node<string>* string_4 = new node<string>("child4");
node<string>* string_5 = new node<string>("child5");
node<string>* string_6 = new node<string>("child6");
node<string>* string_7 = new node<string>("child7");
    SUBCASE("Hole tree") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_bfs_scan();
        CHECK(*it == "root");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child6");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_bfs_scan());
    }
    SUBCASE("Partial tree") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_3, string_6);
        binary_string_tree.add_sub_node(string_6, string_7);

        auto it = binary_string_tree.begin_bfs_scan();
        CHECK(*it == "root");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == "child7");
        ++it;
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(it == binary_string_tree.end_bfs_scan());
    }
}
// Complex tree
TEST_CASE("bfs_iterator for complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));
node<Complex>* complex_2 = new node<Complex>(Complex(5, 0));
node<Complex>* complex_3 = new node<Complex>(Complex(0, -5));
node<Complex>* complex_4 = new node<Complex>(Complex(0, 0));
node<Complex>* complex_5 = new node<Complex>(Complex(0, 0));

    SUBCASE("Hole tree") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_bfs_scan();
        CHECK(*it == Complex(1, 2));
        ++it;
        CHECK(*it == Complex(3, 4));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(0, -5));
       
    }
    SUBCASE("Partial tree") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);
        auto it = binary_complex_tree.begin_bfs_scan();
        CHECK(*it == Complex(1, 2));
        ++it;
        CHECK(*it == Complex(3, 4));
        ++it;
        ++it;
        CHECK(*it == Complex(0, -5));
      
    }
}
// Unary tree
TEST_CASE("bfs_iterator for unary tree") {
    tree<int, 1> unary_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
   
    unary_tree.add_root(int_root);
    unary_tree.add_sub_node(int_root, int_1);
    unary_tree.add_sub_node(int_1, int_2);
    unary_tree.add_sub_node(int_2, int_3);
    unary_tree.add_sub_node(int_3, int_4);
    unary_tree.add_sub_node(int_4, int_5);
    unary_tree.add_sub_node(int_5, int_6);
    unary_tree.add_sub_node(int_6, int_7);
    unary_tree.add_sub_node(int_7, int_8);
    unary_tree.add_sub_node(int_8, int_9);
    unary_tree.add_sub_node(int_9, int_10);
    unary_tree.add_sub_node(int_10, int_11);
    unary_tree.add_sub_node(int_11, int_12);
    unary_tree.add_sub_node(int_12, int_13);
    unary_tree.add_sub_node(int_13, int_14);

    auto it = unary_tree.begin_bfs_scan();
    CHECK(*it == 0);
    ++it;
    CHECK(*it == 1);
    for (int i = 0; i < 13; i++) {
        ++it;
    }
    CHECK(*it == 14);
    ++it;
    CHECK(it == unary_tree.end_bfs_scan());
}

// Quad tree
TEST_CASE("bfs_iterator for quad tree") {
    tree<int, 4> quad_tree;
     node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Hole tree") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_2, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_3, int_15);
        quad_tree.add_sub_node(int_3, int_16);

        auto it = quad_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 16);
        ++it;
        CHECK(it == quad_tree.end_bfs_scan());
    }
    SUBCASE("Partial tree") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_3, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_4, int_15);
        quad_tree.add_sub_node(int_4, int_16);

        auto it = quad_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 16);
        ++it;
        CHECK(it == quad_tree.end_bfs_scan());
    }
}
// Ten tree
TEST_CASE("bfs_iterator for ten tree") {
    tree<int, 10> ten_tree;
      node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Hole tree") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        ten_tree.add_sub_node(int_5, int_15);
        ten_tree.add_sub_node(int_5, int_16);

        auto it = ten_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 16);
        ++it;
        CHECK(it == ten_tree.end_bfs_scan());
    }
    SUBCASE("Partial tree") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_2, int_7);
        ten_tree.add_sub_node(int_2, int_8);
        ten_tree.add_sub_node(int_2, int_9);
        ten_tree.add_sub_node(int_2, int_10);
        ten_tree.add_sub_node(int_3, int_11);
        ten_tree.add_sub_node(int_3, int_12);
        ten_tree.add_sub_node(int_4, int_13);
        ten_tree.add_sub_node(int_4, int_14);
        ten_tree.add_sub_node(int_5, int_15);

        auto it = ten_tree.begin_bfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == 7);
        ++it;
        for (int i = 0; i < 3; i++) {
            ++it;
        }
        CHECK(*it == 11);
       
    }
}
// dfs_iterator
// Int tree
TEST_CASE("dfs_iterator for int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
  
    SUBCASE("Hole tree") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 13; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        CHECK(it == binary_int_tree.end_dfs_scan());
    }
    SUBCASE("Partial tree") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_3, int_6);
        binary_int_tree.add_sub_node(int_6, int_7);
        binary_int_tree.add_sub_node(int_6, int_8);
        binary_int_tree.add_sub_node(int_7, int_9);

        auto it = binary_int_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
            ++it;
        ++it;
        CHECK(it == binary_int_tree.end_dfs_scan());
    }
}
// String tree
TEST_CASE("dfs_iterator for string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("root");
node<string>* string_1 = new node<string>("child1");
node<string>* string_2 = new node<string>("child2");
node<string>* string_3 = new node<string>("child3");
node<string>* string_4 = new node<string>("child4");
node<string>* string_5 = new node<string>("child5");
node<string>* string_6 = new node<string>("child6");
node<string>* string_7 = new node<string>("child7");
    SUBCASE("Hole tree") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_dfs_scan();
        CHECK(*it == "root");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child5");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_dfs_scan());
    }
    SUBCASE("Partial tree") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_3, string_6);
        binary_string_tree.add_sub_node(string_6, string_7);

        auto it = binary_string_tree.begin_dfs_scan();
        CHECK(*it == "root");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == "child5");
        ++it;
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(it == binary_string_tree.end_dfs_scan());
    }
}
// Complex tree
TEST_CASE("dfs_iterator for complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));
node<Complex>* complex_2 = new node<Complex>(Complex(5, 0));
node<Complex>* complex_3 = new node<Complex>(Complex(0, -5));
node<Complex>* complex_4 = new node<Complex>(Complex(0, 0));
node<Complex>* complex_5 = new node<Complex>(Complex(0, 0));

    SUBCASE("Hole tree") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_dfs_scan();
        CHECK(*it == Complex(1, 2));
        ++it;
        CHECK(*it == Complex(3, 4));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(0, 0));
       
    }
    SUBCASE("Partial tree") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);
        auto it = binary_complex_tree.begin_dfs_scan();
        CHECK(*it == Complex(1, 2));
        ++it;
        CHECK(*it == Complex(3, 4));
        ++it;
        ++it;
        CHECK(*it == Complex(0, 0));
        
    }
}
// Unary tree
TEST_CASE("dfs_iterator for unary tree") {
    tree<int, 1> unary_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
   
    unary_tree.add_root(int_root);
    unary_tree.add_sub_node(int_root, int_1);
    unary_tree.add_sub_node(int_1, int_2);
    unary_tree.add_sub_node(int_2, int_3);
    unary_tree.add_sub_node(int_3, int_4);
    unary_tree.add_sub_node(int_4, int_5);
    unary_tree.add_sub_node(int_5, int_6);
    unary_tree.add_sub_node(int_6, int_7);
    unary_tree.add_sub_node(int_7, int_8);
    unary_tree.add_sub_node(int_8, int_9);
    unary_tree.add_sub_node(int_9, int_10);
    unary_tree.add_sub_node(int_10, int_11);
    unary_tree.add_sub_node(int_11, int_12);
    unary_tree.add_sub_node(int_12, int_13);
    unary_tree.add_sub_node(int_13, int_14);

    auto it = unary_tree.begin_dfs_scan();
    CHECK(*it == 0);
    ++it;
    CHECK(*it == 1);
    for (int i = 0; i < 13; i++) {
        ++it;
    }
    CHECK(*it == 14);
    ++it;
    CHECK(it == unary_tree.end_dfs_scan());
}
// Quad tree
TEST_CASE("dfs_iterator for quad tree") {
    tree<int, 4> quad_tree;
     node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Hole tree") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_2, int_12);
        quad_tree.add_sub_node(int_3, int_13);
        quad_tree.add_sub_node(int_3, int_14);
        quad_tree.add_sub_node(int_3, int_15);
        quad_tree.add_sub_node(int_3, int_16);

        auto it = quad_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
        CHECK(it == quad_tree.end_dfs_scan());
    }
    SUBCASE("Partial tree") {
        quad_tree.add_root(int_root);
        quad_tree.add_sub_node(int_root, int_1);
        quad_tree.add_sub_node(int_root, int_2);
        quad_tree.add_sub_node(int_root, int_3);
        quad_tree.add_sub_node(int_root, int_4);
        quad_tree.add_sub_node(int_1, int_5);
        quad_tree.add_sub_node(int_1, int_6);
        quad_tree.add_sub_node(int_1, int_7);
        quad_tree.add_sub_node(int_1, int_8);
        quad_tree.add_sub_node(int_2, int_9);
        quad_tree.add_sub_node(int_2, int_10);
        quad_tree.add_sub_node(int_2, int_11);
        quad_tree.add_sub_node(int_3, int_12);
        quad_tree.add_sub_node(int_3, int_13);

        auto it = quad_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == 9);
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == 13);
      
    }
}
// Ten tree
TEST_CASE("dfs_iterator for ten tree") {
    tree<int, 10> ten_tree;
      node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
    node<int>* int_15 = new node<int>(15);
    node<int>* int_16 = new node<int>(16);
    SUBCASE("Hole tree") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_1, int_7);
        ten_tree.add_sub_node(int_1, int_8);
        ten_tree.add_sub_node(int_1, int_9);
        ten_tree.add_sub_node(int_1, int_10);
        ten_tree.add_sub_node(int_1, int_11);
        ten_tree.add_sub_node(int_1, int_12);
        ten_tree.add_sub_node(int_1, int_13);
        ten_tree.add_sub_node(int_1, int_14);
        ten_tree.add_sub_node(int_5, int_15);
        ten_tree.add_sub_node(int_5, int_16);

        auto it = ten_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 15; i++) {
            ++it;
        }
        CHECK(*it == 4);
        ++it;
        CHECK(it == ten_tree.end_dfs_scan());
    }
    SUBCASE("Partial tree") {
        ten_tree.add_root(int_root);
        ten_tree.add_sub_node(int_root, int_1);
        ten_tree.add_sub_node(int_root, int_2);
        ten_tree.add_sub_node(int_root, int_3);
        ten_tree.add_sub_node(int_root, int_4);
        ten_tree.add_sub_node(int_1, int_5);
        ten_tree.add_sub_node(int_1, int_6);
        ten_tree.add_sub_node(int_2, int_7);
        ten_tree.add_sub_node(int_2, int_8);
        ten_tree.add_sub_node(int_2, int_9);
        ten_tree.add_sub_node(int_2, int_10);
        ten_tree.add_sub_node(int_3, int_11);
        ten_tree.add_sub_node(int_3, int_12);
        ten_tree.add_sub_node(int_4, int_13);
        ten_tree.add_sub_node(int_4, int_14);

        auto it = ten_tree.begin_dfs_scan();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 6; i++) {
            ++it;
        }
        CHECK(*it == 9);
        for (int i = 0; i < 7; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        CHECK(it == ten_tree.end_dfs_scan());
    }
}

// min_heap_iterator
// Int tree
TEST_CASE("min_heap_iterator for int tree") {
    tree<int> binary_int_tree;
    node<int>* int_root = new node<int>(0);
    node<int>* int_1 = new node<int>(1);
    node<int>* int_2 = new node<int>(2);
    node<int>* int_3 = new node<int>(3);
    node<int>* int_4 = new node<int>(4);
    node<int>* int_5 = new node<int>(5);
    node<int>* int_6 = new node<int>(6);
    node<int>* int_7 = new node<int>(7);
    node<int>* int_8 = new node<int>(8);
    node<int>* int_9 = new node<int>(9);
    node<int>* int_10 = new node<int>(10);
    node<int>* int_11 = new node<int>(11);
    node<int>* int_12 = new node<int>(12);
    node<int>* int_13 = new node<int>(13);
    node<int>* int_14 = new node<int>(14);
   
    SUBCASE("Dicreasing order") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_1);
        binary_int_tree.add_sub_node(int_root, int_2);
        binary_int_tree.add_sub_node(int_1, int_3);
        binary_int_tree.add_sub_node(int_1, int_4);
        binary_int_tree.add_sub_node(int_2, int_5);
        binary_int_tree.add_sub_node(int_2, int_6);
        binary_int_tree.add_sub_node(int_3, int_7);
        binary_int_tree.add_sub_node(int_3, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_4, int_10);
        binary_int_tree.add_sub_node(int_5, int_11);
        binary_int_tree.add_sub_node(int_5, int_12);
        binary_int_tree.add_sub_node(int_6, int_13);
        binary_int_tree.add_sub_node(int_6, int_14);

        auto it = binary_int_tree.begin_my_heap();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 13; i++) {
            ++it;
        }
        CHECK(*it == 14);
        ++it;
        CHECK(it == binary_int_tree.end_my_heap());
    }
    SUBCASE("Random order") {
        binary_int_tree.add_root(int_root);
        binary_int_tree.add_sub_node(int_root, int_7);
        binary_int_tree.add_sub_node(int_root, int_3);
        binary_int_tree.add_sub_node(int_7, int_1);
        binary_int_tree.add_sub_node(int_7, int_4);
        binary_int_tree.add_sub_node(int_3, int_2);
        binary_int_tree.add_sub_node(int_3, int_5);
        binary_int_tree.add_sub_node(int_1, int_6);
        binary_int_tree.add_sub_node(int_1, int_13);
        binary_int_tree.add_sub_node(int_4, int_8);
        binary_int_tree.add_sub_node(int_4, int_9);
        binary_int_tree.add_sub_node(int_13, int_10);
        binary_int_tree.add_sub_node(int_13, int_11);

        auto it = binary_int_tree.begin_my_heap();
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        for (int i = 0; i < 11; i++) {
            ++it;
        }
        CHECK(*it == 13);
        ++it;
        CHECK(it == binary_int_tree.end_my_heap());
    }
}
// String tree
TEST_CASE("min_heap_iterator for string tree") {
    tree<string> binary_string_tree;
    node<string>* string_root = new node<string>("aroot");
node<string>* string_1 = new node<string>("child1");
node<string>* string_2 = new node<string>("child2");
node<string>* string_3 = new node<string>("child3");
node<string>* string_4 = new node<string>("child4");
node<string>* string_5 = new node<string>("child5");
node<string>* string_6 = new node<string>("child6");
node<string>* string_7 = new node<string>("child7");
    SUBCASE("Dicreasing order") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_1);
        binary_string_tree.add_sub_node(string_root, string_2);
        binary_string_tree.add_sub_node(string_1, string_3);
        binary_string_tree.add_sub_node(string_1, string_4);
        binary_string_tree.add_sub_node(string_2, string_5);
        binary_string_tree.add_sub_node(string_2, string_6);
        binary_string_tree.add_sub_node(string_3, string_7);

        auto it = binary_string_tree.begin_my_heap();
        CHECK(*it == "aroot");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child6");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_my_heap());
    }
    SUBCASE("Random order") {
        binary_string_tree.add_root(string_root);
        binary_string_tree.add_sub_node(string_root, string_7);
        binary_string_tree.add_sub_node(string_root, string_3);
        binary_string_tree.add_sub_node(string_7, string_1);
        binary_string_tree.add_sub_node(string_7, string_4);
        binary_string_tree.add_sub_node(string_3, string_2);
        binary_string_tree.add_sub_node(string_3, string_5);
        binary_string_tree.add_sub_node(string_1, string_6);

        auto it = binary_string_tree.begin_my_heap();
        CHECK(*it == "aroot");
        ++it;
        CHECK(*it == "child1");
        for (int i = 0; i < 5; i++) {
            ++it;
        }
        CHECK(*it == "child6");
        ++it;
        ++it;
        CHECK(it == binary_string_tree.end_my_heap());
    }
}
// Complex tree
TEST_CASE("min_heap_iterator for complex tree") {
    tree<Complex> binary_complex_tree;
node<Complex>* complex_root = new node<Complex>(Complex(1, 2));
node<Complex>* complex_1 = new node<Complex>(Complex(3, 4));
node<Complex>* complex_2 = new node<Complex>(Complex(5, 0));
node<Complex>* complex_3 = new node<Complex>(Complex(0, -5));
node<Complex>* complex_4 = new node<Complex>(Complex(0, 0));
node<Complex>* complex_5 = new node<Complex>(Complex(0, 0));

    SUBCASE("Dicreasing order") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_1);
        binary_complex_tree.add_sub_node(complex_root, complex_2);
        binary_complex_tree.add_sub_node(complex_1, complex_3);
        binary_complex_tree.add_sub_node(complex_1, complex_4);
        binary_complex_tree.add_sub_node(complex_2, complex_5);

        auto it = binary_complex_tree.begin_my_heap();
        CHECK(*it == Complex(0, 0));
        ++it;
        CHECK(*it == Complex(0, 0));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(5, 0));
      
    }
    SUBCASE("Random order") {
        binary_complex_tree.add_root(complex_root);
        binary_complex_tree.add_sub_node(complex_root, complex_5);
        binary_complex_tree.add_sub_node(complex_root, complex_3);
        binary_complex_tree.add_sub_node(complex_5, complex_1);
        binary_complex_tree.add_sub_node(complex_5, complex_4);
        binary_complex_tree.add_sub_node(complex_3, complex_2);

        auto it = binary_complex_tree.begin_my_heap();
        CHECK(*it == Complex(0, 0));
        ++it;
        CHECK(*it == Complex(0, 0));
        for (int i = 0; i < 2; i++) {
            ++it;
        }
        CHECK(*it == Complex(5, 0));
       
    }
}

// Unary tree, Quad tree, Ten tree : no min heap testing needed because all aspects are tested in previous tests

// complex class functions
// operator<
TEST_CASE("operator< for complex class") {
    SUBCASE("Equal") {
        Complex c1(1, 2);
        Complex c2(1, 2);
        CHECK(!(c1 < c2));
    }
    SUBCASE("Equal norm") {
        Complex c1(1, 2);
        Complex c2(2, 1);
        CHECK(!(c1 < c2));
    }
    SUBCASE("Real part") {
        Complex c1(1, 2);
        Complex c2(2, 2);
        CHECK(c1 < c2);
    }
    SUBCASE("Imaginary part") {
        Complex c1(1, 2);
        Complex c2(1, 3);
        CHECK(c1 < c2);
    }
}
// operator>
TEST_CASE("operator> for complex class") {
    SUBCASE("Equal") {
        Complex c1(1, 2);
        Complex c2(1, 2);
        CHECK(!(c1 > c2));
    }
    SUBCASE("Equal norm") {
        Complex c1(1, 2);
        Complex c2(2, 1);
        CHECK(!(c1 > c2));
    }
    SUBCASE("Real part") {
        Complex c1(1, 2);
        Complex c2(2, 2);
        CHECK(!(c1 > c2));
    }
    SUBCASE("Imaginary part") {
        Complex c1(1, 2);
        Complex c2(1, 3);
        CHECK(!(c1 > c2));
    }
}
// operator==
TEST_CASE("operator== for complex class") {
    SUBCASE("Equal") {
        Complex c1(1, 2);
        Complex c2(1, 2);
        CHECK(c1 == c2);
    }
    SUBCASE("Equal norm") {
        Complex c1(1, 2);
        Complex c2(2, 1);
        CHECK(!(c1 == c2));
    }
    SUBCASE("Equal norm, negative") {
        Complex c1(1, -2);
        Complex c2(-1, 2);
        CHECK(!(c1 == c2));
    }
    SUBCASE("Real part") {
        Complex c1(1, 2);
        Complex c2(2, 2);
        CHECK(!(c1 == c2));
    }
    SUBCASE("Imaginary part") {
        Complex c1(1, 2);
        Complex c2(1, 3);
        CHECK(!(c1 == c2));
    }
}
// operator!=
TEST_CASE("operator!= for complex class") {
    SUBCASE("Equal") {
        Complex c1(1, 2);
        Complex c2(1, 2);
        CHECK(!(c1 != c2));
    }
    SUBCASE("Equal norm") {
        Complex c1(1, 2);
        Complex c2(2, 1);
        CHECK(c1 != c2);
    }
    SUBCASE("Real part") {
        Complex c1(1, 2);
        Complex c2(2, 2);
        CHECK(c1 != c2);
    }
    SUBCASE("Imaginary part") {
        Complex c1(1, 2);
        Complex c2(1, 3);
        CHECK(c1 != c2);
    }
}
// to_string
TEST_CASE("to_string for complex class") {
    SUBCASE("Real part, positive") {
        Complex c(5, 0);
        CHECK(c.to_str() == "5");
    }
    SUBCASE("Real part, negative") {
        Complex c(-5, 0);
        CHECK(c.to_str() == "-5");
    }
    SUBCASE("Imaginary part, positive") {
        Complex c(0, 5);
        CHECK(c.to_str() == "5i");
    }
    SUBCASE("Imaginary part, negative") {
        Complex c(0, -5);
        CHECK(c.to_str() == "-5i");
    }
    SUBCASE("Both parts, positive") {
        Complex c(5, 5);
        CHECK(c.to_str() == "5 + 5i");
    }
    SUBCASE("Both parts, negative") {
        Complex c(-5, -5);
        CHECK(c.to_str() == "-5 - 5i");
    }
    SUBCASE("Both parts, mixed") {
        Complex c(5, -5);
        CHECK(c.to_str() == "5 - 5i");
    }
    SUBCASE("Both parts, mixed 2") {
        Complex c(-5, 5);
        CHECK(c.to_str() == "-5 + 5i");
    }
    SUBCASE("Both parts, zero") {
        Complex c(0, 0);
        CHECK(c.to_str() == "0");
    }
}
