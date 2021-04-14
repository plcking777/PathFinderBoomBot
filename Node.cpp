#include "Node.h"
#include <list>

Node::Node() {
	this->Score = 2147483647;
}

Node::Node(int row, int col, int width, int tot_rows) {
	this->row = row;
	this->col = col;
	this->width = width;
	this->tot = tot_rows;
	
	this->Type = 0;

	sf::RectangleShape rs(sf::Vector2f(100, 100));
	rs.setSize(sf::Vector2f(width, width));
	rs.setPosition(sf::Vector2f(row*width, col*width));
	this->rs = rs;

	this->Score = 2147483647;

	sf::Vector2i temp = sf::Vector2i(50,50); // Bigger then board
	this->CameFrom = temp;

}



sf::Vector2i Node::GetPos() {
	sf::Vector2i pos;
	pos.y = this->row;
	pos.x = this->col;
	return pos;
}

void Node::Draw(sf::RenderWindow &window) {

	window.draw(this->rs);
}


void Node::SetWall() {
	this->Type = 1;
	this->rs.setFillColor(sf::Color::Black);
}
void Node::SetStart() {
	this->Type = 2;
	this->rs.setFillColor(sf::Color::Cyan);
}
void Node::SetEnd() {
	this->Type = 3;
	this->rs.setFillColor(sf::Color::Yellow);
}
void Node::SetOpen() {
	this->Type = 4;
	this->rs.setFillColor(sf::Color::Green);
}
void Node::SetClosed() {
	this->Type = 5;
	this->rs.setFillColor(sf::Color::Red);
}

void Node::AddNeigbor(Node a) {
	this->Neighbors.push_back(a);
}

unsigned char Node::GetType() {
	return this->Type;
}

std::vector<Node> Node::GetNeigbors() {
	return this->Neighbors;
}


void Node::SetPath() {
	this->Type = 6;
	this->rs.setFillColor(sf::Color::Magenta);
}