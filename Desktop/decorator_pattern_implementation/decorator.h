#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "textprocess.h"
#include "echo.h"
class Decorator: public TextProcessor {
protected:
TextProcessor * component;
public:
Decorator (TextProcessor * t): component {t} {}
virtual ~Decorator ();

};
#endif
