#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "node.hpp"

using sf::RenderWindow;
using std::vector;

template <typename T, size_t k = 2>
class tree {
   private:
    node<T>* root;

    // Helper function to draw a node and its children
    void drawNode(RenderWindow& window, node<T>* n, float x, float y, float levelWidth, float currentLevel = 0) {
        if (!n) return;

        // Draw the current node
        sf::CircleShape shape(20);  // Example size, adjust as needed
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
        window.draw(shape);

        // Draw the node's data
        sf::Text text;
        text.setString(std::to_string(n->getData()));  // Simplified, ensure conversion is possible
        text.setPosition(x + 10, y + 5);               // Adjust as needed
        window.draw(text);

        auto children = n->getChildren();
        size_t numChildren = children.size();
        float childX = x - (levelWidth / 2) + (levelWidth / (numChildren + 1));
        for (auto& child : children) {
            // Draw line to child
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 20, y + 20)),       // Adjust based on shape size and position
                sf::Vertex(sf::Vector2f(childX + 20, y + 100))  // Example child position, adjust as needed
            };
            window.draw(line, 2, sf::Lines);

            // Recursively draw child
            drawNode(window, child, childX, y + 100, levelWidth / numChildren, currentLevel + 1);
            childX += levelWidth / (numChildren + 1);
        }
    }

   public:
    tree() : root(nullptr) {}
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
        return false;
    }

    void draw(RenderWindow& window) {
        if (root) {
            drawNode(window, root, window.getSize().x / 2, 50, window.getSize().x / 4);
        }
    }
};