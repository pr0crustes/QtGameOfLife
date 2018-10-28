#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QRandomGenerator>
#include <QMessageBox>


class Board : public QWidget {
		Q_OBJECT

	public:
		explicit Board(int size, int scale, QWidget *parent = nullptr)
			: QWidget(parent), boardSize(size), boardScale(scale) {}
		void setupBoard();
		void resetBoard();
		void doCicle();
		void flipRandomTile();

	private:
		int boardSize;
		int boardScale;
		QVector<Tile *> tiles;

		Tile* tile(int row, int col);
		QVector<Tile *> tilesAroundTile(int row, int col);
		bool inRange(int row, int col);
		int aliveCount(QVector<Tile *>* tiles);

};

#endif // BOARD_H
