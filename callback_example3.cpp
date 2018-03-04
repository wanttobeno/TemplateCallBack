/*
  **********************************************************************
  *                                                                    *
  *       Variable Parameter Call-Back Template (version 0.0.1)        *
  *                                                                    *
  * Source Code: Example 3                                             *
  * Author: Arash Partow - 2000                                        *
  * URL: http://www.partow.net/programming/templatecallback/index.html *
  *                                                                    *
  * Copyright Notice:                                                  *
  * Free use of this library is permitted under the guidelines and     *
  * in accordance with the most current version of the Common Public   *
  * License.                                                           *
  * http://www.opensource.org/licenses/cpl.php                         *
  *                                                                    *
  **********************************************************************
*/


#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include "CallBack.h"

class AClass
{
public:

   AClass(unsigned int id)
   : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      printf("AClass[%d]: %s\n",id_,str.c_str());
      return true;
   }

   bool method4(int a, int b, int c, int d)
   {
      printf("Method 4 - %d\t%d\t%d\t%d\n",a,b,c,d);
      return true;
   }

   bool method3(int a, int b, int c)
   {
      printf("Method 3 - %d\t%d\t%d\n",a,b,c);
      return true;
   }

   bool method2(int a, int b)
   {
      printf("Method 2 - %d\t%d\n",a,b);
      return true;
   }

   bool method1(int a)
   {
      printf("Method 1 - %d\n",a);
      return true;
   }

   bool method0()
   {
      printf("Method 0\n");
      return true;
   }

   void methodv()
   {
      printf("Method void\n");
   }

private:

   unsigned int id_;
};

typedef CallBack<AClass, bool, int, int ,int, int> cb4_t;
typedef CallBack<AClass, bool, int, int ,int> cb3_t;
typedef CallBack<AClass, bool, int, int> cb2_t;
typedef CallBack<AClass, bool, int> cb1_t;
typedef CallBack<AClass, bool> cb0_t;
typedef CallBack<AClass, void> cbv_t;


int main()
{
   AClass aclass(1);

   cb4_t cb4(&aclass,&AClass::method4);
   cb3_t cb3(&aclass,&AClass::method3);
   cb2_t cb2(&aclass,&AClass::method2);
   cb1_t cb1(&aclass,&AClass::method1);
   cb0_t cb0(&aclass,&AClass::method0);
   cbv_t cbv(&aclass,&AClass::methodv);

   cb4(1,2,3,4);
   cb3(1,2,3);
   cb2(1,2);
   cb1(1);
   cb0();
   cbv();

   return 0;
}
