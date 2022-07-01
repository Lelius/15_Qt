#pragma once

#include <cstdlib>
#include <time.h>

#include <QPair>

class BoxWithChips {
public:
  BoxWithChips();
  BoxWithChips(int);
  BoxWithChips(int, int);
  ~BoxWithChips();

  const int STANDARTSIZEBOX = 4;

  const int *getBoxWithChips();
  int getSizeBox() const;
  int getXNum() const;
  int getYNum() const;

  void randomChips();
  bool searchChip(int);
  bool isMatchingChips();
  int getPosChip(int);
  int getPosEmptyPlace();
  QPair<bool, int>  toTheLeftChip();
  bool toTheRightChip();
  bool toTheUpChip();
  bool toTheDownChip();
  void buildInOrderChips();
  int getChipTheGlobalNumber(int);

private:
  bool setSizeBox(int);

  int xNum;
  int yNum;
  int sizeBox;
  int *boxWithChips;
};
