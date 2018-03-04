/*
  **********************************************************************
  *                                                                    *
  *           Singular Call-Back Template (version 0.0.1)              *
  *                                                                    *
  * Source Code: Example 1                                             *
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


#include <iostream>
#include <string>
#include <vector>

#include "SingularCallBack.h"

class AClass
{
public:

   AClass(unsigned int id)
   : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      std::cout.flush();
      return true;
   }

private:

   unsigned int id_;
};

typedef SingularCallBack<AClass, bool, const std::string&> ACallBack;


int main()
{
   std::vector<ACallBack> callback_list;

   AClass a1(1);
   AClass a2(2);
   AClass a3(3);

   callback_list.push_back(ACallBack(&a1,&AClass::AMethod));
   callback_list.push_back(ACallBack(&a2,&AClass::AMethod));
   callback_list.push_back(ACallBack(&a3,&AClass::AMethod));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i]("abc");
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i].execute("abc");
   }

   return 0;
}
