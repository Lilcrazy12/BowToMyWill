CXX := clang++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRC := $(wildcard ./src/*.cpp) $(wildcard ./src/**/*.cpp)
INC := -I./src

OBJS := $(SRC:.cpp=.o)

BUILD_DIR = build

EXEC := $(BUILD_DIR)/output

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(EXEC): $(SRC) | $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

all: $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)
