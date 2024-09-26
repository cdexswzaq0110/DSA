#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 定義紅黑樹的節點
class Node {
public:
    int value;
    char color; // 'r' for red, 'b' for black
    Node* left;
    Node* right;
    Node* parent;

    Node(int val, char col) : value(val), color(col), left(nullptr), right(nullptr), parent(nullptr) {}
};

// 繪製紅黑樹
void drawNode(sf::RenderWindow& window, Node* node, float x, float y, float offsetX) {
    if (node == nullptr) return;

    // 設置節點圓形的大小和位置
    sf::CircleShape circle(30);
    circle.setPosition(x, y);

    // 設置節點顏色，紅色或黑色
    if (node->color == 'r') {
        circle.setFillColor(sf::Color::Red);
    }
    else {
        circle.setFillColor(sf::Color::Black);
    }

    // 畫節點
    window.draw(circle);

    // 顯示節點數值
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "無法加載字體!" << endl;
        return;
    }
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(node->value));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 15, y + 10); // 放置於圓圈內
    window.draw(text);

    // 繪製左子節點
    if (node->left != nullptr) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 30, y + 30)),
            sf::Vertex(sf::Vector2f(x - offsetX + 30, y + 100))
        };
        window.draw(line, 2, sf::Lines);
        drawNode(window, node->left, x - offsetX, y + 100, offsetX / 2);
    }

    // 繪製右子節點
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
    // 創建一個 800x600 的視窗
    sf::RenderWindow window(sf::VideoMode(800, 600), "紅黑樹");

    // 創建一個紅黑樹的節點作為範例
    Node* root = new Node(10, 'b');
    root->left = new Node(5, 'r');
    root->right = new Node(20, 'r');
    root->left->left = new Node(3, 'b');
    root->left->right = new Node(7, 'b');
    root->right->right = new Node(30, 'b');

    // 主迴圈
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // 清除視窗背景為白色

        // 繪製紅黑樹
        drawNode(window, root, 400, 50, 150);

        window.display(); // 顯示繪製的內容
    }

    return 0;
}
