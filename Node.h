#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Node {

private:
    int row;
    int col;
    int width;
    int tot;
    std::vector<Node> Neighbors;
    

    unsigned char Type;
    sf::RectangleShape rs;
public:
    
    float Score;
    sf::Vector2i CameFrom;

    Node();
    Node(int row, int col, int width, int tot_rows);
    sf::Vector2i GetPos();
    void Draw(sf::RenderWindow &window);
    void SetWall();
    void SetStart();
    void SetEnd();
    void SetOpen();
    void SetPath();
    void SetClosed();
    void AddNeigbor(Node a);

    unsigned char GetType();
    std::vector<Node> GetNeigbors();

    
};