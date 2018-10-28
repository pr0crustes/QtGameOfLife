#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include <QColor>
#include <QMouseEvent>


class Tile : public QLabel {

	public:
		Tile();
		bool isAlive();
		void flipCell();

	protected:
		void mousePressEvent(QMouseEvent *event);

	private:
		bool alive;
		void updateTile();

};

#endif // TILE_H
