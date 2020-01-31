#include <stdlib.h>
#include <gtest/gtest.h>

#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"
#include "queue.h"

// Taken from sample test
#define CS4500_ASSERT_TRUE(a)  \
  ASSERT_EQ((a),true);
#define CS4500_ASSERT_EXIT_ZERO(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

TEST(W1, test1) {
  String * s = new String("Hello");
  String * t = new String("World");
  Object * o = new Object();
  Object * o2 = new Object();
  Queue  * qq = new Queue();
  Queue  * qq1 = new Queue();
  CS4500_ASSERT_TRUE(qq->remove()  == nullptr);
  CS4500_ASSERT_TRUE(qq->peek()  == nullptr);
  CS4500_ASSERT_TRUE(qq->size() == 0);
  CS4500_ASSERT_TRUE(qq1->remove()  == nullptr);
  CS4500_ASSERT_TRUE(qq1->peek()  == nullptr);
  CS4500_ASSERT_TRUE(qq1->size() == 0);
  CS4500_ASSERT_TRUE(qq->add(s) == s);
  CS4500_ASSERT_TRUE(qq1->add(s) == s);

  Object *r1 = qq->peek(); 
  Object *r2 = qq1->peek();
  CS4500_ASSERT_TRUE(r1 == r2);

  CS4500_ASSERT_TRUE(qq->size()  == 1);
  CS4500_ASSERT_TRUE(qq->size()  == qq1->size());
  CS4500_ASSERT_TRUE(qq->remove() == r1);
  CS4500_ASSERT_TRUE(qq->remove() == qq1->remove());
  CS4500_ASSERT_TRUE(qq->size()  == 0);
  CS4500_ASSERT_TRUE(qq->size() == qq1->size());
  
}

TEST(W1, test2) {
  Object * o = new Object();
  Object * o2 = new Object();
  Queue  * qq = new Queue();
  Queue  * qq1 = new Queue();
  CS4500_ASSERT_TRUE(qq->remove()  == nullptr);
  CS4500_ASSERT_TRUE(qq->peek()  == nullptr);
  CS4500_ASSERT_TRUE(qq->size() == 0);
  CS4500_ASSERT_TRUE(qq1->remove()  == nullptr);
  CS4500_ASSERT_TRUE(qq1->peek()  == nullptr);
  CS4500_ASSERT_TRUE(qq1->size() == 0);
  CS4500_ASSERT_TRUE(qq1->add(o) == qq->add(o));
  CS4500_ASSERT_TRUE(qq->add(o) == o);

  Object *r1 = qq->peek(); // Object * o
  Object *r2 = qq1->peek(); // Object * o
  CS4500_ASSERT_TRUE(r1 == r2);
  qq->add(o2);
  qq->add(o2);
  CS4500_ASSERT_TRUE(qq->size()  == 4);
  Object *r3 = qq->peek(); 
  CS4500_ASSERT_TRUE(qq->remove()  == r3);
  CS4500_ASSERT_TRUE(qq->size()  == 3);

  Object *r4 = qq->peek(); 
  CS4500_ASSERT_TRUE(qq->remove()  == r4);
  CS4500_ASSERT_TRUE(qq->size()  == 2);
  CS4500_ASSERT_TRUE(r3  == r4);
  Object *r5 = qq->peek(); 
  CS4500_ASSERT_TRUE(qq->remove()  == r5);
  CS4500_ASSERT_TRUE(qq->size()  == 1);
  Object *r6 = qq->peek(); 
  CS4500_ASSERT_TRUE(qq->remove()  == r6);
  CS4500_ASSERT_TRUE(qq->size()  == 0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
