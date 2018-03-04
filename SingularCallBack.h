/*
  **********************************************************************
  *                                                                    *
  *           Singular Call-Back Template (version 0.0.1)              *
  *                                                                    *
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


#ifndef INCLUDE_SINGULARCALLBACK_H
#define INCLUDE_SINGULARCALLBACK_H

template <class Class, typename ReturnType, typename Parameter>
class SingularCallBack
{
public:

   typedef ReturnType (Class::*Method)(Parameter);

   SingularCallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter parameter)
   {
      return (class_instance_->*method_)(parameter);
   }

   ReturnType execute(Parameter parameter)
   {
      return operator()(parameter);
   }

private:

   Class*  class_instance_;
   Method  method_;
};

#endif

