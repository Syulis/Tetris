#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;

void getline(char line[], int maxline);
void getline(char line[], int maxline){
  int c, i;
  for(i = 0; i < maxline - 1 && (c = getchar()) != '\n'; ++i)
  line[i] = c;
  line[i] = '\0';
}

int random_choice_number(int number_);
int random_choice_number(int number_){
  srand((unsigned int)time(NULL));
  int number = rand() % number_;
  return number;
}

// class Pseudo_WBuffer{
//   public:
//     void write(string write_text);
//     void reset();
//     void update();
//   private:
//     string text1 = "";
//     string text2 = "";
// };
//
// void Pseudo_WBuffer::write(string write_text){
//   text1 += write_text;
// }
//
// void Pseudo_WBuffer::reset(){
//   text1 = "";
// }
//
// void Pseudo_WBuffer::update(){
//   system("cls");
//   printf("%s\n", text1.c_str());
// }
