#include "NumberGrid.h"

NumberGrid::NumberGrid() 
	: mHeight(300), mWidth(400), mMax(255), mGrid((mHeight * mWidth), 0){}
NumberGrid::NumberGrid( const int& height, const int& width )
	: mHeight(height), mWidth(width), mMax(255), mGrid((mHeight * mWidth), 0){} 

int NumberGrid::getHeight() const{
	return mHeight;	
}
int NumberGrid::getWidth() const{
	return mWidth;
}
int NumberGrid::getMaxNumber() const{
	return mMax;
} 
void NumberGrid::setGridSize( const int& height, const int& width ){
	if (height >= 2 && width >= 2) {
		mHeight = height;
		mWidth = width;
		mGrid.resize(mHeight * mWidth);
	}
}
void NumberGrid::setMaxNumber( const int& number ){
	if (number >= 0) {
		mMax = number;
	}
} 
const std::vector<int>& NumberGrid::getNumbers() const{
	return mGrid;
} 
int NumberGrid::index( const int& row, const int& column ) const{
	return (row * mWidth) + column;
} 
bool NumberGrid::indexValid( const int& row, const int& column ) const{
	// Returns true if row and column are both within the range of the grid. Otherwise returns false.
	return row < mHeight && row >= 0 && column < mWidth && column >= 0;
} 
bool NumberGrid::numberValid( const int& number ) const{
	return (number >= 0 && number <= mMax);
} 
int NumberGrid::getNumber( const int& row, const int& column ) const{
	return indexValid(row, column) ? mGrid[index(row, column)] : -1;
} 
void NumberGrid::setNumber( const int& row, const int& column, const int& number ){
	if (indexValid(row, column) && numberValid(number)) {
		mGrid[index(row, column)] = number;
	}
} 
void NumberGrid::setPPM( PPM& ppm ) const{
	ppm.setHeight(mHeight);
	ppm.setWidth(mWidth);
	ppm.setMaxColorValue(63);
	for (int row = 0; row < mHeight; ++row) {
		for (int col = 0; col < mWidth; ++col) {
			int i = getNumber(row, col);
			if (i == 0) {
				ppm.setPixel(row, col, 0, 0, 0);
			} else if (i == mMax) {
				ppm.setPixel(row, col, 63, 31, 31);
			} else if (i % 8 == 0) {
				ppm.setPixel(row, col, 63, 63, 63);
			} else if (i % 8 == 1) {
				ppm.setPixel(row, col, 63, 31, 31);
			} else if (i % 8 == 2) {
				ppm.setPixel(row, col, 63, 63, 31);
			} else if (i % 8 == 3) {
				ppm.setPixel(row, col, 31, 63, 31);
			} else if (i % 8 == 4) {
				ppm.setPixel(row, col, 0, 0, 0);
			} else if (i % 8 == 5) {
				ppm.setPixel(row, col, 31, 63, 63);
			} else if (i % 8 == 6) {
				ppm.setPixel(row, col, 31, 31, 63);
			} else if (i % 8 == 7) {
				ppm.setPixel(row, col, 63, 31, 63);
			}
		}
	}
}
