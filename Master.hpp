#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <iostream>

#include "Config.hpp"
#include "Yuli.hpp"
#include "Manager.hpp"
#include "Timer.hpp"

class Master{
  public:
    void run();
    void start_nemu();
    void game();
    void pause();
    void gameover();
  private:
    Manager manager;
    Timer update_timer;
    Timer block_move_timer;
    Timer user_action_timer;
    int system = 1;
};

void Master::run(){
  while(system != 0){
    if(system == 1){
      start_nemu();
    }else if(system == 2){
      game();
    }else if(system == 3){
      gameover();
    }
  }
}

void Master::start_nemu(){
  char ch;
  std::system("cls");
  printf("\n        Game Start to Press Enter\n\n           Exit to Press ESC\n");
  while(system == 1){
    if(GetAsyncKeyState(VK_RETURN)){
      ++system;
      manager.set();
    }
    if(GetAsyncKeyState(VK_ESCAPE))system = 0;
  }
}

void Master::game(){
  if(update_timer.watch(1000 / fps))manager.update();
  if(block_move_timer.watch(falltime))if(!manager.blocks_move())++system;
  if(user_action_timer.watch(useractiontime))manager.user_action();
  pause();
}

void Master::pause(){
  if(GetAsyncKeyState(VK_ESCAPE)){
    std::system("cls");
    printf("\n               PAUSE\n\n       RETURN TO GAME : ENTER\n\n            RESTART : 'R'\n\n      RETURN TO START MENU : 'Q'");
    while(!GetAsyncKeyState(VK_RETURN)){
      if(GetAsyncKeyState(0x52)){
        manager.set();
        break;
      }
      if(GetAsyncKeyState(0x51)){
        system = 1;
        break;
      }
    }
  }
}

void Master::gameover(){
  std::system("cls");
  printf("\n\n            --- GameOver ---");
  system = 1;
}

