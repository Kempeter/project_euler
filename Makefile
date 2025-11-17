CXX = g++
CXXFLAGS = -std=c++26 -Wall -Wextra
SRCDIR = src
BINDIR = bin
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
TARGETS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SOURCES))

all: $(TARGETS)

$(BINDIR)/%: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(BINDIR)

.PHONY: all clean