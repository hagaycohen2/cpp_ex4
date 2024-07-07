#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>


#include "node.hpp"
#include "iterators.hpp"

using sf::RenderWindow;
using std::cout;
using std::endl;
using std::vector;

template <typename T, size_t k = 2>
class tree {
   private:
    node<T>* root;
    sf::Font font;
    
    // Helper function to draw a node and its children
    void drawNode(RenderWindow& window, node<T>* n, float x, float y, float levelWidth, float nodesInLevel = 1, float currentLevel = 1) {
        if (!n) return;

        // Draw the current node
        sf::CircleShape shape(20);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
        window.draw(shape);

        // Draw the node's data
        sf::Text text;
        text.setString(std::to_string(n->getData()));
        text.setCharacterSize(12);  
        text.setFont(font);
        text.setFillColor(sf::Color::Black);

        // Calculate text width and height for centering
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(sf::Vector2f(x + shape.getRadius(), y + shape.getRadius()));  // Center text within the circle

        window.draw(text);

        auto children = n->getChildren();
        size_t numChildren = children.size();
        if (numChildren == 0) return;

         // Adjust levelWidth based on the number of children to prevent overlap
    float newLevelWidth = std::max(25.0f, levelWidth / numChildren);

    float childX = x - (levelWidth / 2) + (newLevelWidth / 2); // Start position for the first child
    for (auto& child : children) {
        // Draw line to child
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 25)),
            sf::Vertex(sf::Vector2f(childX + 20, y + 100))};
        window.draw(line, 2, sf::Lines);

        // Recursively draw child
        drawNode(window, child, childX, y + 100, newLevelWidth,numChildren , currentLevel + 1);
        childX += newLevelWidth; // Move to the next child's position
    }
    }

   public:
    tree() : root(nullptr) {
        if (!font.loadFromFile("fonts/Roboto-Regular.ttf")) {
            cout << "Failed to load font" << endl;
        }
    }
    ~tree() {
        if (root) {
            delete root;
        }
    }

    node<T>* getRoot() {
        return this->root;
    }
    void add_root(node<T>* root) {
        this->root = root;
    }
    bool add_sub_node(node<T>* parent, node<T>* child) {
        if (parent->getNumChildren() < k) {
            parent->addChild(child);
            child->setParent(parent);
            return true;
        }
        cout << "Parent node has maximum number of children" << endl;
        return false;
    }

    void draw(RenderWindow& window) {
        if (root) {
            drawNode(window, root, window.getSize().x / 2, 50, window.getSize().x);
        }
    }
    
    index_iterator<T, k> begin_index_iterator(size_t index) {
        return index_iterator<T, k>(root, index);
    }
    index_iterator<T, k> end_index_iterator() {
        return index_iterator<T, k>(nullptr, 0);
    }
    index_iterator<T, k> begin_pre_order() {
        return begin_index_iterator(0);
    }
    index_iterator<T, k> end_pre_order() {
        return end_index_iterator();
    }
    index_iterator<T, k> begin_in_order() {
        return begin_index_iterator(k / 2);
    }
    index_iterator<T, k> end_in_order() {
        return end_index_iterator();
    }
    index_iterator<T, k> begin_post_order() {
        return begin_index_iterator(k);
    }
    index_iterator<T, k> end_post_order() {
        return end_index_iterator();
    }
    dfs_iterator<T> begin_dfs_scan() {
        return dfs_iterator<T>(root);
    }
    dfs_iterator<T> end_dfs_scan() {
        return dfs_iterator<T>(nullptr);
    }
    bfs_iterator<T> begin_bfs_scan() {
        return bfs_iterator<T>(root);
    }
    bfs_iterator<T> end_bfs_scan() {
        return bfs_iterator<T>(nullptr);
    }
    min_heap_iterator<T> begin_my_heap() {
        return min_heap_iterator<T>(root);
    }
    min_heap_iterator<T> end_my_heap() {
        return min_heap_iterator<T>(nullptr);
    }
};