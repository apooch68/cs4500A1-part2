 
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
  CS4500_ASSERT_TRUE(qq->remove()  == nullptr);
  CS4500_ASSERT_TRUE(qq->peek()  == nullptr);
  CS4500_ASSERT_TRUE(qq->size() == 0);
  qq->add(s);
  CS4500_ASSERT_TRUE(qq->peek()  ==  s);
  CS4500_ASSERT_TRUE(qq->size()  == 1);
  CS4500_ASSERT_TRUE(qq->remove()  == s);
  CS4500_ASSERT_TRUE(qq->size()  == 0);
}

TEST(W1, test2) {
  String * s = new String("Hello");
  String * t = new String("World");
  Object * o = new Object();
  Object * o2 = new Object();
  Queue  * qq = new Queue();
  qq->add(s);
  qq->add(o);
  qq->add(t);
  qq->add(s);
  CS4500_ASSERT_TRUE(qq->peek()  ==  s);
  CS4500_ASSERT_TRUE(qq->size()  == 4);
  CS4500_ASSERT_TRUE(qq->remove()  == s);
  CS4500_ASSERT_TRUE(qq->peek()  ==  o);
  CS4500_ASSERT_TRUE(qq->size()  == 3);
  CS4500_ASSERT_TRUE(qq->remove()  == o);
  CS4500_ASSERT_TRUE(qq->peek()  ==  t);
  CS4500_ASSERT_TRUE(qq->size()  == 2);
  CS4500_ASSERT_TRUE(qq->remove()  == t);
  CS4500_ASSERT_TRUE(qq->peek()  ==  s);
  CS4500_ASSERT_TRUE(qq->size()  == 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
