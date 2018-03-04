/*
  **********************************************************************
  *                                                                    *
  *       Variable Parameter Call-Back Template (version 0.0.1)        *
  *                                                                    *
  * Source Code: Example 4                                             *
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

typedef CallBack<AClass, bool, int, int ,int, int> callback_type4;
typedef CallBack<AClass, bool, int, int ,int>      callback_type3;
typedef CallBack<AClass, bool, int, int>           callback_type2;
typedef CallBack<AClass, bool, int>                callback_type1;
typedef CallBack<AClass, bool>                     callback_type0;
typedef CallBack<AClass, void>                     callback_typev;


int main()
{
   AClass aclass(1);

   callback_type4 cb4(&aclass, &AClass::method4);
   callback_type3 cb3(&aclass, &AClass::method3);
   callback_type2 cb2(&aclass, &AClass::method2);
   callback_type1 cb1(&aclass, &AClass::method1);
   callback_type0 cb0(&aclass, &AClass::method0);
   callback_typev cbv(&aclass, &AClass::methodv);

   std::vector<std::pair<int,void*> > callback_list;

   callback_list.push_back(std::pair<int ,void*>( 4, static_cast<void*>(&cb4)));
   callback_list.push_back(std::pair<int ,void*>( 3, static_cast<void*>(&cb3)));
   callback_list.push_back(std::pair<int ,void*>( 2, static_cast<void*>(&cb2)));
   callback_list.push_back(std::pair<int ,void*>( 1, static_cast<void*>(&cb1)));
   callback_list.push_back(std::pair<int ,void*>( 0, static_cast<void*>(&cb0)));
   callback_list.push_back(std::pair<int ,void*>(-1, static_cast<void*>(&cbv)));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      switch (callback_list[i].first)
      {
         case  4: (*static_cast<callback_type4*>(callback_list[i].second))(1,2,3,4);
                  break;

         case  3: (*static_cast<callback_type3*>(callback_list[i].second))(1,2,3);
                  break;

         case  2: (*static_cast<callback_type2*>(callback_list[i].second))(1,2);
                  break;

         case  1: (*static_cast<callback_type1*>(callback_list[i].second))(1);
                  break;

         case  0: (*static_cast<callback_type0*>(callback_list[i].second))();
                  break;

         case -1: (*static_cast<callback_typev*>(callback_list[i].second))();
                  break;
      }
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      switch (callback_list[i].first)
      {
         case  4: static_cast<callback_type4*>(callback_list[i].second)->execute(1,2,3,4);
                  break;

         case  3: static_cast<callback_type3*>(callback_list[i].second)->execute(1,2,3);
                  break;

         case  2: static_cast<callback_type2*>(callback_list[i].second)->execute(1,2);
                  break;

         case  1: static_cast<callback_type1*>(callback_list[i].second)->execute(1);
                  break;

         case  0: static_cast<callback_type0*>(callback_list[i].second)->execute();
                  break;

         case -1: static_cast<callback_typev*>(callback_list[i].second)->execute();
                  break;
      }
   }

   return 0;
}
