#include "helper.h"  // Your file, with any C++ code that you need
#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"
#include "queue.h"
 
void FAIL() {   exit(1);    }
void OK(const char* m) { /** print m */ }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }
 
void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  Object * o = new Object();
  Object * o2 = new Object();
  Queue  * qq = new Queue;
  t_true(qq->remove()  == nullptr);
  t_true(qq->peek()  == nullptr);
  t_true(qq->size() == 0);
  qq->add(s);
  t_true(qq->peek()  ==  s);
  t_true(qq->size()  == 1);
  t_true(qq->remove()  == s);
  t_true(qq->size()  == 0);

  OK("1");
}
 
void test2() {

  String * s = new String("Hello");
  String * t = new String("World");
  Object * o = new Object();
  Object * o2 = new Object();
  Queue  * qq = new Queue;
  qq->add(s);
  qq->add(o);
  qq->add(t);
  qq->add(s);
  t_true(qq->peek()  ==  s);
  t_true(qq->size()  == 4);
  t_true(qq->remove()  == s);
  t_true(qq->peek()  ==  o);
  t_true(qq->size()  == 3);
  t_true(qq->remove()  == o);
  t_true(qq->peek()  ==  t);
  t_true(qq->size()  == 2);
  t_true(qq->remove()  == t);
  t_true(qq->peek()  ==  s);
  t_true(qq->size()  == 1);
  OK("2");
}
 

int main() {
  test1();
  return 0;
}
