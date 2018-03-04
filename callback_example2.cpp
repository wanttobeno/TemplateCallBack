/*
  **********************************************************************
  *                                                                    *
  *           Singular Call-Back Template (version 0.0.1)              *
  *                                                                    *
  * Source Code: Example 2                                             *
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

class BaseClass
{
   public:

   virtual ~BaseClass() {}

   virtual bool DerivedMethod(const std::string& str)
   {
      std::cout << "Base Class" << std::endl;
      return true;
   }
};

class AClass : public BaseClass
{
public:

   AClass(unsigned int id)
   : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};

class BClass : public BaseClass
{
public:

   BClass(unsigned int id)
   : id_(id)
   {}

   bool BMethod(const std::string& str)
   {
      std::cout << "BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};

typedef SingularCallBack<BaseClass, bool, const std::string&> BaseCallBack;


int main()
{
   std::vector<BaseCallBack> callback_list;

   AClass a(1);
   BClass b(2);

   callback_list.push_back(BaseCallBack(&a,&BaseClass::DerivedMethod));
   callback_list.push_back(BaseCallBack(&b,&BaseClass::DerivedMethod));

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
