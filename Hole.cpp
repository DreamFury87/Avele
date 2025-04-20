#include "Hole.h"
#include <iostream>
using namespace std;

Hole::Hole(sf::Vector2f pos) {
	cout << "Hole's constructor is working" << endl;

	texture.loadFromFile(hole_texture, false);
	shape.setTexture(&texture);

	position = pos;
	shape.setPosition(position);

	cout << "Hole is created!" << endl;
}

//Конструктор по умолчанию
Hole::Hole() {
	cout << "Hole's constructor is working" << endl;

	texture.loadFromFile(hole_texture, false);
	shape.setTexture(&texture);

	position = { 100.f, 100.f };
	shape.setPosition(position);

	cout << "Hole is created!" << endl;
}

//Деструктор
Hole::~Hole() {
	cout << "Hole is deleted!" << endl;
}

//Обновление количества камней в лунке
void Hole::Update(int) {

}

//Изменение позиции
void Hole::Set_Position(sf::Vector2f pos) {
	position = pos;
}

//Отрисовка
void Hole::Render(const sf::RenderTarget &target) {
	//target.draw(this->shape);
	target.draw(shape);
}