#ifndef _SERIAL_VIEW_
#define _SERIAL_VIEW_

#include "observer.h"

#include "sequence.h"

class SerialView : public Observer {
public:
  SerialView(Sequence*, Sequence*, Sequence*, Sequence*);
  virtual ~SerialView();
  virtual void update();
private:
  Sequence* s1_;
  Sequence* s2_;
  Sequence* s3_;
  Sequence* s4_;
};

#endif
