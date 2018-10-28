#include "tile.h"


Tile::Tile() : QLabel(), alive(false) {
	this->setAlignment(Qt::AlignCenter);
	this->setFont(QFont("Arial", 30, QFont::Bold));
	this->updateTile();
}


bool Tile::isAlive() {
	return this->alive;
}


void Tile::flipCell() {
	this->alive = !this->alive;
	this->updateTile();
}


void Tile::updateTile() {
	QColor color = this->isAlive() ? QColor(0, 0, 0) : QColor(255, 255, 255);
	this->setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setColor(QPalette::Background, color);
	this->setPalette(palette);
}


void Tile::mousePressEvent(QMouseEvent *event) {
	this->flipCell();
}
