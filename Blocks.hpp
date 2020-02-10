class Blocks{
  public:
    void set(int* pointer);

    int put();

    void change_block();

    void expansion();
    void reduction();

    void line_clear();
    int line_check();

    void right_move();
    void left_move();

    int right_move_check();
    int left_move_check();

    void right_rotation();
    void left_rotation();

    int right_rotation_check();
    int left_rotation_check();

    int fall();
    int fall_check();

    void hold();

    void add_len();
    void len_check();
    void add_score();

    void user_action();

    void left_move_action();
    void right_move_action();
    void drop_action();
    void harddrop_action();

    void right_rotation_action();
    void left_rotation_action();

    void hold_action();

    char return_next();
    char return_hold();
    int return_score();
    int return_len();

  private:
    int* p_field;
    char blocks[7] = {'T', 'S', 'Z', 'I', 'O', 'J', 'L'};
    char next_block;
    char block;
    char hold_block;
    bool held = false;
    int score;
    int len_number;
    bool len = false;
    int rotation_number = 0;
    int location;
};

void Blocks::set(int* pointer){
  p_field = pointer;
  next_block = blocks[random_choice_number(7)];
  sleep(1);
  block = blocks[random_choice_number(7)];
  hold_block = ' ';
  score = 0;
  put();
}

int Blocks::put(){
  rotation_number = 0;
  location = (width / 2) + width + width;
  switch(block){
    case 'T':
      if(*(p_field + location - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location) != 0 || *(p_field + location + 1) != 0)return 0;
      break;
    case 'I':
      if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0 || *(p_field + location) != 0 ||  *(p_field + location + width) != 0)return 0;
      break;
    case 'S':
      if(*(p_field + location - width) != 0 || *(p_field + location + width + 1) != 0 || *(p_field + location - 1) != 0 ||  *(p_field + location) != 0)return 0;
      break;
    case 'Z':
      if(*(p_field + location - width - 1) != 0 || *(p_field + location - width) != 0 || *(p_field + location) != 0 ||  *(p_field + location - 1) != 0)return 0;
      break;
    case 'O':
      if(*(p_field + location - width - 1) != 0 || *(p_field + location - width) != 0 || *(p_field + location - 1) != 0 ||  *(p_field + location) != 0)return 0;
      break;
    case 'J':
      if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0 || *(p_field + location - 1) != 0 ||  *(p_field + location) != 0)return 0;
      break;
    case 'L':
      if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0 || *(p_field + location) != 0 ||  *(p_field + location + 1) != 0)return 0;
      break;
  }
  expansion();
  return 1;
}

void Blocks::change_block(){
  block = next_block;
  next_block = blocks[random_choice_number(7)];
}

void Blocks::expansion(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          *(p_field + location) = 1;
          *(p_field + location - width) = 1;
          *(p_field + location - 1) = 1;
          *(p_field + location + 1) = 1;
          break;
        case 'S':
          *(p_field + location - width) = 2;
          *(p_field + location - width + 1) = 2;
          *(p_field + location - 1) = 2;
          *(p_field + location) = 2;
          break;
        case 'Z':
          *(p_field + location - width - 1) = 3;
          *(p_field + location - width) = 3;
          *(p_field + location) = 3;
          *(p_field + location + 1) = 3;
          break;
        case 'I':
          *(p_field + location - width - width) = 4;
          *(p_field + location - width) = 4;
          *(p_field + location) = 4;
          *(p_field + location + width) = 4;
          break;
        case 'O':
          *(p_field + location - width - 1) = 5;
          *(p_field + location - width) = 5;
          *(p_field + location - 1) = 5;
          *(p_field + location) = 5;
          break;
        case 'J':
          *(p_field + location - width - width) = 6;
          *(p_field + location - width) = 6;
          *(p_field + location - 1) = 6;
          *(p_field + location) = 6;
          break;
        case 'L':
          *(p_field + location - width - width) = 7;
          *(p_field + location - width) = 7;
          *(p_field + location) = 7;
          *(p_field + location + 1) = 7;
          break;
      }
      break;

    case 1:
      switch(block){
        case 'T':
          *(p_field + location) = 1;
          *(p_field + location - width) = 1;
          *(p_field + location - 1) = 1;
          *(p_field + location + width) = 1;
          break;
        case 'S':
          *(p_field + location - width - 1) = 2;
          *(p_field + location - 1) = 2;
          *(p_field + location) = 2;
          *(p_field + location + width) = 2;
          break;
        case 'Z':
          *(p_field + location - width) = 3;
          *(p_field + location) = 3;
          *(p_field + location - 1) = 3;
          *(p_field + location + width - 1) = 3;
          break;
        case 'I':
          *(p_field + location - 2) = 4;
          *(p_field + location - 1) = 4;
          *(p_field + location) = 4;
          *(p_field + location + 1) = 4;
          break;
        case 'O':
          *(p_field + location) = 5;
          *(p_field + location - 1) = 5;
          *(p_field + location + width - 1) = 5;
          *(p_field + location + width) = 5;
          break;
        case 'J':
          *(p_field + location - 2) = 6;
          *(p_field + location - 1) = 6;
          *(p_field + location) = 6;
          *(p_field + location + width) = 6;
          break;
        case 'L':
          *(p_field + location - 2) = 7;
          *(p_field + location - 1) = 7;
          *(p_field + location) = 7;
          *(p_field + location - width) = 7;
          break;
      }
      break;

    case 2:
      switch(block){
        case 'T':
          *(p_field + location - 1) = 1;
          *(p_field + location) = 1;
          *(p_field + location + 1) = 1;
          *(p_field + location + width) = 1;
          break;
        case 'S':
          *(p_field + location + width - 1) = 2;
          *(p_field + location + width) = 2;
          *(p_field + location) = 2;
          *(p_field + location + 1) = 2;
          break;
        case 'Z':
          *(p_field + location - 1) = 3;
          *(p_field + location) = 3;
          *(p_field + location + width) = 3;
          *(p_field + location + width + 1) = 3;
          break;
        case 'I':
          *(p_field + location - width) = 4;
          *(p_field + location) = 4;
          *(p_field + location + width) = 4;
          *(p_field + location + width + width) = 4;
          break;
        case 'O':
          *(p_field + location) = 5;
          *(p_field + location + 1) = 5;
          *(p_field + location + width) = 5;
          *(p_field + location + width + 1) = 5;
          break;
        case 'J':
          *(p_field + location) = 6;
          *(p_field + location + 1) = 6;
          *(p_field + location + width) = 6;
          *(p_field + location + width + width) = 6;
          break;
        case 'L':
          *(p_field + location - 1) = 7;
          *(p_field + location) = 7;
          *(p_field + location + width) = 7;
          *(p_field + location + width + width) = 7;
          break;
      }
      break;

    case 3:
      switch(block){
        case 'T':
          *(p_field + location) = 1;
          *(p_field + location - width) = 1;
          *(p_field + location + 1) = 1;
          *(p_field + location + width) = 1;
          break;
        case 'S':
          *(p_field + location - width) = 2;
          *(p_field + location) = 2;
          *(p_field + location + 1) = 2;
          *(p_field + location + width + 1) = 2;
          break;
        case 'Z':
          *(p_field + location - width + 1) = 3;
          *(p_field + location + 1) = 3;
          *(p_field + location) = 3;
          *(p_field + location + width) = 3;
          break;
        case 'I':
          *(p_field + location - 1) = 4;
          *(p_field + location) = 4;
          *(p_field + location + 1) = 4;
          *(p_field + location + 2) = 4;
          break;
        case 'O':
          *(p_field + location) = 5;
          *(p_field + location + 1) = 5;
          *(p_field + location - width) = 5;
          *(p_field + location - width + 1) = 5;
          break;
        case 'J':
          *(p_field + location - width) = 6;
          *(p_field + location) = 6;
          *(p_field + location + 1) = 6;
          *(p_field + location + 2) = 6;
          break;
        case 'L':
          *(p_field + location + width) = 7;
          *(p_field + location) = 7;
          *(p_field + location + 1) = 7;
          *(p_field + location + 2) = 7;
          break;
      }
      break;
  }
}

void Blocks::reduction(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          *(p_field + location) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location + 1) = 0;
          break;
        case 'S':
          *(p_field + location - width) = 0;
          *(p_field + location - width + 1) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          break;
        case 'Z':
          *(p_field + location - width - 1) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          break;
        case 'I':
          *(p_field + location - width - width) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'O':
          *(p_field + location - width - 1) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          break;
        case 'J':
          *(p_field + location - width - width) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          break;
        case 'L':
          *(p_field + location - width - width) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          break;
      }
      break;

    case 1:
      switch(block){
        case 'T':
          *(p_field + location) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'S':
          *(p_field + location - width - 1) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'Z':
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location + width - 1) = 0;
          break;
        case 'I':
          *(p_field + location - 2) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          break;
        case 'O':
          *(p_field + location) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location + width - 1) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'J':
          *(p_field + location - 2) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'L':
          *(p_field + location - 2) = 0;
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location - width) = 0;
          break;
      }
      break;

    case 2:
      switch(block){
        case 'T':
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'S':
          *(p_field + location + width - 1) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          break;
        case 'Z':
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location + width + 1) = 0;
          break;
        case 'I':
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location + width + width) = 0;
          break;
        case 'O':
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location + width + 1) = 0;
          break;
        case 'J':
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location + width + width) = 0;
          break;
        case 'L':
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          *(p_field + location + width + width) = 0;
          break;
      }
      break;

    case 3:
      switch(block){
        case 'T':
          *(p_field + location) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'S':
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + width + 1) = 0;
          break;
        case 'Z':
          *(p_field + location - width + 1) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + width) = 0;
          break;
        case 'I':
          *(p_field + location - 1) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + 2) = 0;
          break;
        case 'O':
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location - width) = 0;
          *(p_field + location - width + 1) = 0;
          break;
        case 'J':
          *(p_field + location - width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + 2) = 0;
          break;
        case 'L':
          *(p_field + location + width) = 0;
          *(p_field + location) = 0;
          *(p_field + location + 1) = 0;
          *(p_field + location + 2) = 0;
          break;
      }
      break;
  }
}

void Blocks::line_clear(){
  int height_number = line_check();
  if(height_number){
    for(int height_range = 1; height_range < height_number; ++height_range){
      for(int width_range = 0; width_range < width; ++width_range){
        *(p_field + ((height_number - height_range) * width) + width_range) = *(p_field + ((height_number - height_range) * width) - width + width_range);
      }
    }
    add_score();
    line_clear();
  }
}

int Blocks::line_check(){
  int count = 0;
  for(int height_range = 1; height_range < height + 1; ++height_range){
    count = 0;
    for(int width_range = 1; width_range < width + 1; ++width_range){
      if(*(p_field + (width * height_range) - width_range) != 0){
        count++;
      }else{
        break;
      }
      if(count == width){
        len = true;
        add_len();
        return height_range;
      }
    }
  }
  return 0;
}

void Blocks::right_move(){
  if(right_move_check()){
    reduction();
    ++location;
    expansion();
  }
}

void Blocks::left_move(){
  if(left_move_check()){
    reduction();
    --location;
    expansion();
  }
}

int Blocks::right_move_check(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 2) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1) != 0 || *(p_field + location + 2 - width) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1 - width - width) != 0 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1 - width - width) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1 - width - width) != 0)return 0;
          break;
      }
      break;
    case 1:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location - width) != 0 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + width) != 0 || *(p_field + location + 1) != 0 || *(p_field + location - width + 1) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
      }
      break;
    case 2:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1) != 0 || *(p_field + location + 2 + width) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0 || *(p_field + location + 1 + width + width) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 2 + width) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + 1 + width) != 0 || *(p_field + location + 1 + width + width) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0 || *(p_field + location + 1 + width + width) != 0)return 0;
          break;
      }
      break;
    case 3:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 2) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1 - width) != 0 || *(p_field + location + 2) != 0 || *(p_field + location + 2 + width) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2 - width) != 0 || *(p_field + location + 2) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 3 || *(p_field + location + 3) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2 - width) != 0 || *(p_field + location + 2) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 3 || *(p_field + location + 3) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 3 || *(p_field + location + 3) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
      }
      break;
  }
  return 1;
}

int Blocks::left_move_check(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 2 || *(p_field + location - 1) != 0 || *(p_field + location + 2 - width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width - width) != 0 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'O':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 2 - width) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 - width - width) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width - width) != 0 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
      }
      break;
    case 1:
      switch(block){
        case 'T':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 2 || *(p_field + location - 2 - width) != 0 || *(p_field + location - 2) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location -2 + width) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 3 || *(p_field + location - 3))return 0;
          break;
        case 'O':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 2 + width) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 3 || *(p_field + location - 3) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 3 || *(p_field + location - 3) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
      }
      break;
    case 2:
      switch(block){
        case 'T':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 2 || *(p_field + location - 1) != 0 || *(p_field + location - 2 + width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0 || *(p_field + location - 1 + width + width) != 0)return 0;
          break;
        case 'O':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0 || *(p_field + location - 1 + width + width) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1 + width) != 0 || *(p_field + location - 1 + width + width) != 0)return 0;
          break;
      }
      break;
    case 3:
      switch(block){
        case 'T':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 1 || *(p_field + location - width) != 0 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0)return 0;
          break;
        case 'O':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
      }
      break;
  }
  return 1;
}

void Blocks::right_rotation(){
  if(right_rotation_check()){
    reduction();
    switch(rotation_number){
      case 0:
        rotation_number = 3;
        break;
      case 1:
        rotation_number = 0;
        break;
      case 2:
        rotation_number = 1;
        break;
      case 3:
        rotation_number = 2;
        break;
    }
    expansion();
  }
}

void Blocks::left_rotation(){
  if(left_rotation_check()){
    reduction();
    switch(rotation_number){
      case 0:
        rotation_number = 1;
        break;
      case 1:
        rotation_number = 2;
        break;
      case 2:
        rotation_number = 3;
        break;
      case 3:
        rotation_number = 0;
        break;
    }
    expansion();
  }
}

int Blocks::right_rotation_check(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0)return 0;
          break;
        case 'S':
          if(*(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 2 || (location / width) * width > location - 1 || *(p_field + location + 2) != 0 || *(p_field + location + 1) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1) != 0 || *(p_field + location + 2) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width ||((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 2) != 0 || *(p_field + location + width) != 0)return 0;
          break;
      }
      break;
    case 1:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location - width) != 0 || *(p_field + location - width + 1) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'I':
          if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'O':
          if(*(p_field + location - width - 1) != 0 || *(p_field + location - width) != 0)return 0;
          break;
        case 'J':
          if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location - width - width) != 0)return 0;
          break;
      }
      break;
    case 2:
      switch(block){
        case 'T':
          if(*(p_field + location - width) != 0)return 0;
          break;
        case 'S':
        if(*(p_field + location - 1) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'Z':
          if(*(p_field + location - width) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 2 || ((location / width) * width) - 1 + width < location + 1 || *(p_field + location - 2) != 0 || *(p_field + location - 1) != 0 || *(p_field + location + 1) != 0)return 0;
          break;
        case 'O':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - width) != 0)return 0;
          break;
      }
      break;
    case 3:
      switch(block){
        case 'T':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 1 || *(p_field + location + width - 1) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width + width || *(p_field + location + width + width) != 0 || *(p_field + location + width) != 0 || *(p_field + location - width) != 0)return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width + width || *(p_field + location + width + width) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width + width || (location / width) * width > location - 2 || *(p_field + location - 1) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
      }
      break;
  }
  return 1;
}

int Blocks::left_rotation_check(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0)return 0;
          break;
        case 'S':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width || width*height - 1 < location + width || *(p_field + location - 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'I':
          if((location / width) * width > location - 2 || ((location / width) * width) - 1 + width < location + 1 || *(p_field + location - 2) != 0 || *(p_field + location - 1) != 0 || *(p_field + location + 1))return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + width - 1) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width || (location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'L':
          if((location / width) * width > location - 2 || *(p_field + location - 2) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
      }
      break;
    case 1:
      switch(block){
        case 'T':
          if(((location / width) * width) - 1 + width < location + 1  || *(p_field + location + 1) != 0)return 0;
          break;
        case 'S':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location - 1 + width) != 0)return 0;
          break;
        case 'Z':
          if(((location / width) * width) - 1 + width < location + 1  || *(p_field + location + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width + width || *(p_field + location + width + width) != 0 || *(p_field + location + width) != 0 || *(p_field + location - width) != 0)return 0;
          break;
        case 'O':
          if(((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width + width || ((location / width) * width) - 1 + width < location + 1 || *(p_field + location + 1) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width + width || *(p_field + location + width + width) != 0 || *(p_field + location + width) != 0)return 0;
          break;
      }
      break;
    case 2:
      switch(block){
        case 'T':
          if(*(p_field + location - width) != 0)return 0;
          break;
        case 'S':
          if(*(p_field + location - width) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'Z':
          if(*(p_field + location + 1) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'I':
          if(((location / width) * width) - 1 + width < location + 2 || (location / width) * width > location - 1 || *(p_field + location + 2) != 0 || *(p_field + location + 1) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'O':
          if(*(p_field + location - width) != 0 || *(p_field + location - width + 1) != 0)return 0;
          break;
        case 'J':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location - width) != 0 || *(p_field + location + 2) != 0)return 0;
          break;
        case 'L':
          if(((location / width) * width) - 1 + width < location + 2 || *(p_field + location + 1) != 0 || *(p_field + location + 2) != 0)return 0;
          break;
      }
      break;
    case 3:
      switch(block){
        case 'T':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'S':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location + 1 - width) != 0)return 0;
          break;
        case 'Z':
          if((location / width) * width > location - 1 || *(p_field + location - 1 - width) != 0 || *(p_field + location - width) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location - width) != 0 || *(p_field + location - width - width) != 0)return 0;
          break;
        case 'O':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - 1 - width) != 0)return 0;
          break;
        case 'J':
          if((location / width) * width > location - 1 || *(p_field + location - 1) != 0 || *(p_field + location - width - width) != 0)return 0;
          break;
        case 'L':
          if(*(p_field + location - width - width) != 0 || *(p_field + location - width) != 0)return 0;
          break;
      }
      break;
  }
  return 1;
}

int Blocks::fall(){
  if(!fall_check()){
    held = false;
    line_clear();
    len_check();
    change_block();
    if(put()){
    }else{
      return 0;
    }
  }
  reduction();
  location = location + width;
  expansion();
  return 1;
}

int Blocks::fall_check(){
  switch(rotation_number){
    case 0:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width || *(p_field + location - 1 + width) != 0 || *(p_field + location + width) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'S':
          if(width*height - 1 < location + width || *(p_field + location - 1 + width) != 0 || *(p_field + location + width) != 0 || *(p_field + location + 1) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + 1 + width) != 0 || *(p_field + location - 1) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width + width || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width || *(p_field + location - 1 + width) != 0 ||  *(p_field + location + width) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width || *(p_field + location + width - 1) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
      }
      break;
    case 1:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width + width || *(p_field + location - 1 + width) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'S':
          if(width*height - 1 < location + width + width || *(p_field + location - 1 + width) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width + width || *(p_field + location + width) != 0 || *(p_field + location - 1 + width + width) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width || *(p_field + location + width - 2) != 0 || *(p_field + location + width - 1) != 0 || *(p_field + location + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width + width || *(p_field + location - 1 + width + width) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width + width || *(p_field + location + width - 2) != 0 || *(p_field + location + width - 1) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width || *(p_field + location + width - 2) != 0 || *(p_field + location + width - 1) != 0 || *(p_field + location + width) != 0)return 0;
          break;
      }
      break;
    case 2:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width + width || *(p_field + location - 1 + width) != 0 || *(p_field + location + width + width) != 0 || *(p_field + location + 1 + width) != 0)return 0;
          break;
        case 'S':
          if(width*height - 1 < location + width + width || *(p_field + location - 1 + width + width) != 0 || *(p_field + location + width + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width + width || *(p_field + location + width - 1) != 0 || *(p_field + location + width + width) != 0 || *(p_field + location + width + width + 1) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width + width + width || *(p_field + location + width + width + width) != 0)return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width + width || *(p_field + location + 1 + width + width) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width + width + width || *(p_field + location + width + 1) != 0 || *(p_field + location + width + width + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width + width + width || *(p_field + location + width - 1) != 0 || *(p_field + location + width + width + width) != 0)return 0;
          break;
      }
      break;
    case 3:
      switch(block){
        case 'T':
          if(width*height - 1 < location + width + width || *(p_field + location + 1 + width) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'S':
          if(width*height - 1 < location + width + width || *(p_field + location + width) != 0 || *(p_field + location + width + width + 1) != 0)return 0;
          break;
        case 'Z':
          if(width*height - 1 < location + width + width || *(p_field + location + width + 1) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
        case 'I':
          if(width*height - 1 < location + width || *(p_field + location + width + 2) != 0 || *(p_field + location + width + 1) != 0 || *(p_field + location + width - 1) != 0)return 0;
          break;
        case 'O':
          if(width*height - 1 < location + width || *(p_field + location + width) != 0 || *(p_field + location + width + 1) != 0)return 0;
          break;
        case 'J':
          if(width*height - 1 < location + width || *(p_field + location + width + 2) != 0 || *(p_field + location + width + 1) != 0 || *(p_field + location + width) != 0)return 0;
          break;
        case 'L':
          if(width*height - 1 < location + width + width || *(p_field + location + width + 2) != 0 || *(p_field + location + width + 1) != 0 || *(p_field + location + width + width) != 0)return 0;
          break;
      }
      break;
  }
  return 1;
}

void Blocks::hold(){
  if(!held){
    reduction();
    char now = block;
    held = true;
    if(hold_block != ' '){
      block = hold_block;
    }else{
      change_block();
    }
    hold_block = now;
    put();
  }
}

void Blocks::add_len(){
    len_number++;
}

void Blocks::len_check(){
  if(len){
    len = false;
  }else{
    len_number = 0;
  }
}

void Blocks::add_score(){
  if(len_number != 0 ? score += 100 * len_number : score += 25);
}

void Blocks::user_action(){
  if(GetAsyncKeyState(rightkey))right_move();
  if(GetAsyncKeyState(leftkey))left_move();
  if(GetAsyncKeyState(dropkey))drop_action();
  if(GetAsyncKeyState(harddropkey))harddrop_action();
  if(GetAsyncKeyState(rightrotationkey))right_rotation();
  if(GetAsyncKeyState(leftrotationkey))left_rotation();
  if(GetAsyncKeyState(holdkey))hold_action();
}

void Blocks::drop_action(){
  score++;
  fall();
}

void Blocks::harddrop_action(){
  score += 5;
  while(fall_check())fall();
}

void Blocks::hold_action(){
  hold();
}

char Blocks::return_next(){
  return next_block;
}

char Blocks::return_hold(){
  return hold_block;
}

int Blocks::return_score(){
  return score;
}

int Blocks::return_len(){
  return len_number;
}