#pragma once

#include <cstdlib>
#include <time.h>

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
  int getPosEmptyPlace();
  bool toTheLeftChip();
  bool toTheRightChip();
  bool toTheUpChip();
  bool toTheBottomChip();
  void buildInOrderChips();
  int getChipTheGlobalNumber(int);

private:
  bool setSizeBox(int);

  int xNum;
  int yNum;
  int sizeBox;
  int *boxWithChips;
};
