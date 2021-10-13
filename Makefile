CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic

.PHONY: all
all: main.cpp
	@echo "With libstdc++..."
	@$(CXX) $(CXXFLAGS) $^
	@./a.out
	@echo "With libc++..."
	@$(CXX) $(CXXFLAGS) -stdlib=libc++ $^
	@./a.out
