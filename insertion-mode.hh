#ifndef INSERTION_MODE_HH 
#define INSERTION_MODE_HH 

enum Mode {
  INITIAL,
  BEFORE_HTML
};

class insertion_mode {
  private:
    static int state;

  public:
    static void switchToBfrHTML(); 
    
    static int getState();
};


#endif
