#include <Servo.h>

class Motor
{
 public:
  Motor(int pin, int lower = 0, int upper = 180)
  : pin_(pin),
    lower_(lower),
    upper_(upper)
  {
  }
  ~Motor(){}

  void attach()
  {
    servo_.attach(pin_);
  }

  void move(int deg)
  {
    servo_.write(deg);
  }
  
  void test()
  {
    for (int deg = lower_; deg <= upper_; deg += 1) 
    {
      servo_.write(deg);
      delay(15);
    }
    delay(2000);
    
    for (int deg = upper_; deg >= lower_; deg -= 1) 
    {
      servo_.write(deg);
      delay(15);
    }
    delay(2000);
  }

 private:
  Servo servo_;

  int pin_;
  
  int upper_;
  int lower_;
};

class Articulation : public Motor
{
 public:
  Articulation(int pin, int lower = 0, int upper = 180) 
  : Motor(pin, lower, upper)
  {
    
  }
};

class Finger : public Motor
{
 public:
  Finger(int pin, int open, int close, int lower = 0, int upper = 180) 
  : Motor(pin, lower, upper),
    open_(open),
    close_(close)
  {
    
  }

  void open()
  {
    for (int pos = close_; pos <= open_; pos += 1) 
    {
      move(pos);
      delay(15);
    }
  }

  void close()
  {
    for (int pos = open_; pos <= close_; pos += 1) 
    {
      move(pos);
      delay(15);
    }
  }

 private:
  int open_;
  int close_;
};

Articulation artic1(8);
Articulation artic2(9, 90 - 30, 90 + 30);
Articulation artic3(10, 90 - 30, 90 + 30);
Articulation artic4(11, 90 - 30, 90 + 30);
Articulation artic5(12, 0, 180);

Finger finger(13, 70, 40, 70, 40);

void setup() 
{
//  artic1.attach();
  artic2.attach();
//  artic3.attach();
//  artic4.attach();
//  artic5.attach();
//
//  finger.attach();
}

void loop() 
{ 
  artic2.test();
}
