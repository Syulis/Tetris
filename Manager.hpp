#include "Blocks.hpp"
#include "Console.hpp"

using namespace std;

class Manager{
  public:
    void set();
    void update();

    void user_action();
    int blocks_move();
  private:
    int field[height][width];
    Blocks blocks;
    Console cc;
};

void Manager::set(){
  std::system("cls");
  for(int height_range = 0; height_range < height; ++height_range){
    for(int width_range = 0; width_range < width; ++width_range){
      field[height_range][width_range] = 0;
    }
  }
  int* fp = &field[0][0];
  AllocConsole();
  for(int i = 0; i < 3; ++i){
    std::system("cls");
    printf("\n\n               %d", 3-i);
    if(i != 2){
      sleep(1);
    }else{
      blocks.set(fp);
    }
  }
}

void Manager::update(){
  std::system("cls");
  for(int height_range = 0; height_range < height; ++height_range){
    if(height_range < 2)continue;
    printf("     ");
    for(int width_range = 0; width_range < width; ++width_range){
      switch(field[height_range][width_range]){
        case 0:
          printf("@");
          break;
        case 1:
          cc.set_text_purple();
          printf("¡");
          break;
        case 2:
          cc.set_text_green();
          printf("¡");
          break;
        case 3:
          cc.set_text_red();
          printf("¡");
          break;
        case 4:
          cc.set_text_rightblue();
          printf("¡");
          break;
        case 5:
          cc.set_text_yellow();
          printf("¡");
          break;
        case 6:
          cc.set_text_blue();
          printf("¡");
          break;
        case 7:
          cc.set_text_orange();
          printf("¡");
          break;
      }
      cc.set_text_white();
    }

    printf(" ");
    if(height_range == 3)printf("     SCORE:%08d   LEN:%2d", blocks.return_score(), blocks.return_len());
    if(height_range == 4){
      char next = blocks.return_next();
      printf("     NEXT:");
      switch(next){
        case 'T':
          cc.set_text_purple();
          break;
        case 'S':
          cc.set_text_green();
          break;
        case 'Z':
          cc.set_text_red();
          break;
        case 'I':
          cc.set_text_rightblue();
          break;
        case 'O':
          cc.set_text_yellow();
          break;
        case 'J':
          cc.set_text_blue();
          break;
        case 'L':
          cc.set_text_orange();
          break;
      }
      cout << next;
      cc.set_text_white();
    }
    if(height_range == 5){
      char next = blocks.return_hold();
      printf("     HOLD:");
      switch(next){
        case 'T':
          cc.set_text_purple();
          break;
        case 'S':
          cc.set_text_green();
          break;
        case 'Z':
          cc.set_text_red();
          break;
        case 'I':
          cc.set_text_rightblue();
          break;
        case 'O':
          cc.set_text_yellow();
          break;
        case 'J':
          cc.set_text_blue();
          break;
        case 'L':
          cc.set_text_orange();
          break;
      }
      cout << blocks.return_hold();
      cc.set_text_white();
    }
    printf("\n");
  }
  printf("    ");
  for(int width_range = 0; width_range < width; ++width_range)printf(" ");
  printf("  \n");
}

void Manager::user_action(){
  blocks.user_action();
}

int Manager::blocks_move(){
  if(!blocks.fall())return 0;
  return 1;
}