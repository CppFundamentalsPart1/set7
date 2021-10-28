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

BUILD_DIR = ../build/53/

SOURCE = \

OUT = $(BUILD_DIR)$(PROGNAME)
OBJS = $(SOURCE:%.cpp=$(BUILD_DIR)%.o)

all: $(OUT)

debug: CXXFLAGS += -g -Og
debug: all
	echo file $(OUT) > gdbCommands
	echo run $(RUN_ARGS) >> gdbCommands
	gdb -q -x gdbCommands
	rm gdbCommands

$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $(OUT)

$(BUILD_DIR)%.o : %.cpp
	@mkdir -p '$(@D)'
	$(CXX) $(CXXFLAGS) $< -o $@

build: $(OBJS)

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	$(OUT) $(RUN_ARGS)