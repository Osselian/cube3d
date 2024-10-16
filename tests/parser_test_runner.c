/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
// #define RUN_TEST(TestFunc, TestLineNum) \
// { \
//   Unity.CurrentTestName = #TestFunc; \
//   Unity.CurrentTestLineNumber = TestLineNum; \
//   Unity.NumberOfTests++; \
//   if (TEST_PROTECT()) \
//   { \
//       setUp(); \
//       TestFunc(); \
//   } \
//   if (TEST_PROTECT()) \
//   { \
//     tearDown(); \
//   } \
//   UnityConcludeTest(); \
// }

/*=======Automagically Detected Files To Include=====*/
#include "../unity/src/unity.h"
// #include <setjmp.h>
// #include <stdio.h>
// #include "../project/incs/cub3D.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_meta_init_bad(void);
extern void test_meta_init_good(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("../tests/test_parser.c");
  RUN_TEST(test_meta_init_bad);
  RUN_TEST(test_meta_init_good);
  return (UnityEnd());
}