#
#  Singular Call-Back Template (version 0.0.1)
# By Arash Partow - 2000
#
# URL: http://www.partow.net/programming/templatecallback/index.html
#
# Copyright Notice:
# Free use of this library is permitted under the guidelines
# and in accordance with the most current version of the
# Common Public License.
# http://opensource.org/licenses/cpl1.0
#

COMPILER         = -c++
OPTIMIZATION_OPT = -O3
OPTIONS          = -pedantic -ansi -Wall -lstdc++ $(OPTIMIZATION_OPT) -o


all: Example1 Example2 Example3 Example4

Example1: callback_example1.cpp CallBack.h
	$(COMPILER) $(OPTIONS) example1 callback_example1.cpp

Example2: callback_example2.cpp CallBack.h
	$(COMPILER) $(OPTIONS) example2 callback_example2.cpp

Example3: callback_example3.cpp CallBack.h
	$(COMPILER) $(OPTIONS) example3 callback_example3.cpp

Example4: callback_example4.cpp CallBack.h
	$(COMPILER) $(OPTIONS) example4 callback_example4.cpp

clean:
	rm -f core *.o *.bak *stackdump *#
