TARGET      := TP153
BUILD_DIR   := build
SRC_DIR     := src
INC_DIR     := include

ifndef PS4SDK
$(error PS4SDK is not set. Please define PS4SDK environment variable)
endif

CC          := clang
CXX         := clang++
OBJCOPY     := llvm-objcopy

CXXFLAGS    := -target x86_64-scei-ps4-elf -std=c++17 -O2 -fno-builtin -fno-exceptions -fno-rtti -Wall -I$(INC_DIR) -I$(PS4SDK)/include
LDFLAGS     := -target x86_64-scei-ps4-elf -shared -fuse-ld=lld -Wl,--unresolved-symbols=ignore-all -L$(PS4SDK)/lib
LIBS        := -lSceLibKernel -lScePad

SRCS        := $(wildcard $(SRC_DIR)/*.cpp)
OBJS        := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET).prx

$(TARGET).prx: $(TARGET).elf
	$(OBJCOPY) --strip-unneeded $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET).elf $(TARGET).prx
