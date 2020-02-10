#include <windows.h>

class Console{
  public:
    void set_text_red();
    void set_text_yellow();
    void set_text_orange();
    void set_text_rightblue();
    void set_text_blue();
    void set_text_green();
    void set_text_purple();
    void set_text_gray();
    void set_text_white();
  private:
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
};

void Console::set_text_white(){
  SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Console::set_text_red(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
}

void Console::set_text_yellow(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
}

void Console::set_text_orange(){
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN);
}

void Console::set_text_rightblue(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Console::set_text_blue(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}

void Console::set_text_green(){
  SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
}

void Console::set_text_purple(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
}

void Console::set_text_gray(){
  SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

