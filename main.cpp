#include "node.hpp"
#include "tree.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualizer");
      window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    tree<int,10> t;
    node<int>* root = new node<int>(0);
    t.add_root(root);

    node<int>* child1 = new node<int>(1);
    node<int>* child2 = new node<int>(2);
    node<int>* child3 = new node<int>(3);
    node<int>* child4 = new node<int>(4);
    node<int>* child5 = new node<int>(5);
    node<int>* child6 = new node<int>(6);
    node<int>* child7 = new node<int>(7);
    node<int>* child8 = new node<int>(8);
    node<int>* child9 = new node<int>(9);
    node<int>* child10 = new node<int>(10);

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

    cout << "Root: " << t.getRoot()->getData() << endl;
    cout << "Root's children: ";
    for (auto& child : t.getRoot()->getChildren()) {
        cout << child->getData() << " ";
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