class Timer{
  public:
    int watch(int mt);
  private:
    unsigned long int time = clock();
};

int Timer::watch(int mt){
  if(time + mt < clock()){
    time = clock();
    return 1;
  }else{
    return 0;
  }
}

