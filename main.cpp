/**
 * Author: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"

using std::cout;
using std::endl;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualizer");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    tree<Complex, 4> t;
    node<Complex>* root = new node<Complex>(Complex(0, 0));
    t.add_root(root);

    node<Complex>* child1 = new node<Complex>(Complex(1, 1));
    node<Complex>* child2 = new node<Complex>(Complex(2, 2));
    node<Complex>* child3 = new node<Complex>(Complex(3, 3));
    node<Complex>* child4 = new node<Complex>(Complex(4, 3));
    node<Complex>* child5 = new node<Complex>(Complex(5, 0));
    node<Complex>* child6 = new node<Complex>(Complex(0, -5));
    node<Complex>* child7 = new node<Complex>(Complex(0, -1));
    node<Complex>* child8 = new node<Complex>(Complex(-8, 0));
    node<Complex>* child9 = new node<Complex>(Complex(0, -9));
    node<Complex>* child10 = new node<Complex>(Complex(10, 10));

    t.add_sub_node(root, child1);
    t.add_sub_node(root, child2);
    t.add_sub_node(root, child3);
    t.add_sub_node(child1, child4);
    t.add_sub_node(child1, child5);
    t.add_sub_node(child2, child6);
    t.add_sub_node(child2, child7);
    t.add_sub_node(child2, child8);
    t.add_sub_node(child2, child9);
    t.add_sub_node(child3, child10);

cout << "\n        --------------------------" << endl;
cout << " Complex Tree Visualizer and Iterators demo \n" << endl;

    cout << "Root: " << t.getRoot()->getData() << endl;
    cout << "Root's children: \n";
    for (auto& child : t.getRoot()->getChildren()) {
        cout << child->getData() << "\n";
    }
    cout << endl;

    cout << "preorder traversal: \n";
    for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
        cout << *it << "\n";
    }
    cout << endl;

    cout << "inorder traversal: \n";
    for (auto it = t.begin_in_order(); it != t.end_in_order(); ++it) {
        cout << *it << "\n";
    }
    cout << endl;

    cout << "postorder traversal: \n";
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        cout << *it << "\n";
    }
    cout << endl;

    cout << "dfs scan: \n";
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        cout << it->getData() << "\n";
    }
    cout << endl;

    cout << "bfs scan: \n";
    for (auto it = t.begin_bfs_scan(); it != t.end_bfs_scan(); ++it) {
        cout << it->getData() << "\n";
    }
    cout << endl;

    cout << "min heap: \n";
    for (auto it = t.begin_my_heap(); it != t.end_my_heap(); ++it) {
        cout << it->getData() << "\n";
    }
    cout << endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        t.draw(window);
        window.display();
    }

    window.close();
}