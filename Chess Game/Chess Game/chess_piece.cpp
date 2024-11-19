#include <iostream>
#include <gdiplusheaders.h>
using namespace std;

int FILES[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
char RANKS[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

struct gridPosition {
	int file;
	char rank;
};

class chessPiece {
	private:
		gridPosition position;
		int screenPositionX, screenPositionY;
		char color; // 'B' or 'W'
		string imgId;
		Image *imgObject;
	public:
		chessPiece(int file, char rank, char color, string imgId);

		void setPosition(gridPosition newPosition);
		// void setImg(string img);

		virtual bool getPositionConstraints(gridPosition positionToCheck) = 0;
};

chessPiece::chessPiece(int file, char rank, char color, string imgId) {
	gridPosition position;
	position.file = file;
	position.rank = rank;
	
	// Absolute screen position of the chess piece
	int fileIndex, rankIndex;
	int *filePtr = find(&FILES[0], FILES + (sizeof(FILES) / sizeof(int)), file);
	char *rankPtr = find(&RANKS[0], RANKS + (sizeof(RANKS) / sizeof(char)), rank);

	screenPositionX = currentRenderState.width / (rankPtr - RANKS); 
	screenPositionY = currentRenderState.height / (filePtr - FILES);

	// Set variables

	this->position = position;
	this->color = color;
	this->imgId = imgId;
	this->imgObject = new Image(L"C:\\Users\\Great\\OneDrive\\Documents\\Personal Projects\\Chess Game\\Images\\Blank.png");
}

void chessPiece::setPosition(gridPosition newPosition) {
	if (getPositionConstraints(newPosition) == true) {
		this->position = newPosition;
	}
}

/*
void chessPiece::setImg(string img) {
	this->img = img;
} 
*/
