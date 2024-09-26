#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// �w�q���¾𪺸`�I
class Node {
public:
    int value;
    char color; // 'r' for red, 'b' for black
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, char col) : value(val), color(col), left(nullptr), right(nullptr), parent(nullptr) {}
};

// ø�s���¾�
void drawNode(sf::RenderWindow& window, Node* node, float x, float y, float offsetX) {
    if (node == nullptr) return;

    // �]�m�`�I��Ϊ��j�p�M��m
    sf::CircleShape circle(30);
    circle.setPosition(x, y);

    // �]�m�`�I�C��A����ζ¦�
    if (node->color == 'r') {
        circle.setFillColor(sf::Color::Red);
    }
    else {
        circle.setFillColor(sf::Color::Black);
    }

    // �e�`�I
    window.draw(circle);

    // ��ܸ`�I�ƭ�
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "�L�k�[���r��!" << endl;
        return;
    }
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(node->value));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 15, y + 10); // ��m���餺
    window.draw(text);

    // ø�s���l�`�I
    if (node->left != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 30, y + 30)),
            sf::Vertex(sf::Vector2f(x - offsetX + 30, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->left, x - offsetX, y + 100, offsetX / 2);
    }

    // ø�s�k�l�`�I
    if (node->right != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 30, y + 30)),
            sf::Vertex(sf::Vector2f(x + offsetX + 30, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->right, x + offsetX, y + 100, offsetX / 2);
    }
}

int main() {
    // �Ыؤ@�� 800x600 ������
    sf::RenderWindow window(sf::VideoMode(800, 600), "���¾�");

    // �Ыؤ@�Ӭ��¾𪺸`�I�@���d��
    Node* root = new Node(10, 'b');
    root->left = new Node(5, 'r');
    root->right = new Node(20, 'r');
    root->left->left = new Node(3, 'b');
    root->left->right = new Node(7, 'b');
    root->right->right = new Node(30, 'b');

    // �D�j��
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // �M�������I�����զ�

        // ø�s���¾�
        drawNode(window, root, 400, 50, 150);

        window.display(); // ���ø�s�����e
    }

    return 0;
}
