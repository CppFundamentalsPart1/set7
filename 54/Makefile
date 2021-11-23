# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

# If the first argument is "debug"...
ifeq (debug,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "debug"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

CXX = g++
CXXFLAGS = -c -Wall -Werror -std=c++20
PROGNAME = a.out

BUILD_DIR = ../build/54/

SOURCE = \
main.cpp

OUT = $(BUILD_DIR)$(PROGNAME)
OBJS = $(SOURCE:%.cpp=$(BUILD_DIR)%.o)

AR = ar
ARFLAGS = rvs
LIBNAME = lockutil

LIB_DIR = ../build/54/lib/

LSOURCE = \
lock/valid.cpp \
lock/lock1.cpp \
lock/lock2.cpp \
lock/lock3.cpp \
lock/lockpath.cpp \
lock/open.cpp \
lock/stringname.cpp

LOUT =$(LIB_DIR)lib$(LIBNAME).a
LOBJS = $(LSOURCE:%.cpp=$(LIB_DIR)%.o)

LFLAGS	= -L $(LIB_DIR) -l$(LIBNAME)


all: $(OUT)

debug: CXXFLAGS += -g -Og
debug: all
	echo file $(OUT) > gdbCommands
	echo run $(RUN_ARGS) >> gdbCommands
	gdb -q -x gdbCommands
	rm gdbCommands

$(OUT): $(OBJS) $(LOUT)
	$(CXX) $(OBJS) -o $(OUT) $(LFLAGS)

$(BUILD_DIR)%.o : %.cpp
	@mkdir -p '$(@D)'
	$(CXX) $(CXXFLAGS) $< -o $@

build: $(OBJS)

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	$(OUT) $(RUN_ARGS)


lib: $(LOUT)

$(LOUT): $(LOBJS)
	$(AR) $(ARFLAGS) $(LOUT) $(LOBJS)

$(LIB_DIR)%.o : %.cpp
	@mkdir -p '$(@D)'
	$(CXX) $(CXXFLAGS) $< -o $@

cleanlib:
	rm -f $(LOBJS) $(LOUT)

cleanall:
	rm -f $(OBJS) $(OUT) $(LOBJS) $(LOUT)