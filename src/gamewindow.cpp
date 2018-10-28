#include "gamewindow.h"

#define SCALE_FACTOR 10
#define SIZE_NUMBER 30


GameWindow::GameWindow(QWidget *parent) :
	QMainWindow(parent), board(new Board(SIZE_NUMBER, SCALE_FACTOR)) {

	this->board->setupBoard();
	this->setCentralWidget(board);
	this->setWindowTitle("QtGOF");
}


GameWindow::~GameWindow() {
	delete this->board;
}


void GameWindow::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
		case Qt::Key_Space:
			this->board->doCicle();
			break;
		case Qt::Key_F:
			this->board->flipRandomTile();
			break;
		case Qt::Key_T:
			for (int i = 0; i < 1000; i++) {
				this->board->flipRandomTile();
			}
			break;
		case Qt::Key_R:
			this->board->resetBoard();
			break;
		default:
			break;
	}
}
