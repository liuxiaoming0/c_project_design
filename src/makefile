CC := g++
PATH_SRC := .
PATH_ROOT := ..
PATH_BIN := $(PATH_ROOT)/bin
PATH_OBJS := $(PATH_ROOT)/obj
PATH_COMM := $(PATH_ROOT)/comm
PATH_CREATE_PATTERN := $(PATH_ROOT)/create_pattern
PATH_STRUCT_PATTERN := $(PATH_ROOT)/struct_pattern
PATH_BEHAVIOR_PATTERN := $(PATH_ROOT)/behavior_pattern

CFLAGS = -g -o0 -DNDEBUG -Wall -fpic -std=c++17 -Wno-unused-variable
CFLAGS += -fno-elide-constructors
LIBS = $(LIB_CFT) -lpthread -ldl -lrt -lz -lssl -lcrypto -lcurl
EXE = $(PATH_BIN)/pro_design

CFLAGS += -I$(PATH_ROOT)
OBJS = $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_SRC)/*.cpp))
OBJS += $(patsubst $(PATH_COMM)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_COMM)/*.cpp))
OBJS += $(patsubst $(PATH_CREATE_PATTERN)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_CREATE_PATTERN)/*.cpp))
OBJS += $(patsubst $(PATH_STRUCT_PATTERN)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_STRUCT_PATTERN)/*.cpp))
OBJS += $(patsubst $(PATH_BEHAVIOR_PATTERN)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_BEHAVIOR_PATTERN)/*.cpp))

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $^ -Xlinker "-(" $(LIBS) -Xlinker "-)" -o $@

$(PATH_OBJS)/%.o : $(PATH_COMM)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJS)/%.o : $(PATH_CREATE_PATTERN)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJS)/%.o : $(PATH_STRUCT_PATTERN)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJS)/%.o : $(PATH_BEHAVIOR_PATTERN)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJS)/%.o : $(PATH_SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY clean:
	rm -f $(OBJS) $(EXE)