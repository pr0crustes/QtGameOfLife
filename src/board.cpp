#include "board.h"


void Board::setupBoard() {
	QGridLayout* layout = new QGridLayout;

	for (int i = 0; i < this->boardSize * this->boardSize; i++) {
		Tile* tile = new Tile();
		tile->setFixedSize(this->boardScale, this->boardScale);
		layout->addWidget(tile, i / this->boardSize, i % this->boardSize);
		this->tiles << tile;
	}

	this->setLayout(layout);
}


void Board::resetBoard() {
	foreach (Tile* tile, this->tiles) {
		if (tile && tile->isAlive()) {
			tile->flipCell();
		}
	}
}


void Board::doCicle() {
	for (int x = 0; x < this->boardSize; x++) {
		for (int y = 0; y < this->boardSize; y++) {
			Tile* tile = this->tile(x, y);
			if (tile) {
				QVector<Tile *> adjacents = this->tilesAroundTile(x, y);
				int aliveN = this->aliveCount(&adjacents);
				if (tile->isAlive()){
					if (aliveN < 2 || aliveN > 3) {
						tile->flipCell();
					}
				} else if (aliveN == 3) {
					tile->flipCell();
				}
			}
		}
	}
}


Tile* Board::tile(int row, int col) {
	if (this->inRange(row, col)) {
		return this->tiles[this->boardSize * row + col];
	}
	return nullptr;
}


bool Board::inRange(int row, int col) {
	bool positive = row >= 0 && col >= 0;
	bool upper = row < this->boardSize && col < this->boardSize;
	return positive && upper;
}


QVector<Tile *> Board::tilesAroundTile(int row, int col) {
	QVector<Tile *> tilesAround;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			Tile* tile = this->tile(row + i, col + j);
			if (tile) {
				tilesAround << tile;
			}
		}
	}
	return tilesAround;
}


void Board::flipRandomTile() {
	int randomX = QRandomGenerator::global()->bounded(this->boardSize);
	int randomY = QRandomGenerator::global()->bounded(this->boardSize);
	Tile* tile = this->tile(randomX, randomY);
	if (tile) {
		tile->flipCell();
	}
}


int Board::aliveCount(QVector<Tile *> *tiles) {
	int count = 0;
	foreach (Tile *tile, *tiles) {
		if (tile && tile->isAlive()) {
			count++;
		}
	}
	return count;
}
