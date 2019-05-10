#ifndef _OBSERVER_
#define _OBSERVER_

class Observer {
public:
  Observer();
  virtual ~Observer();
  virtual void update() = 0;
private:
};

#endif
