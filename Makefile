CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
EXEC = $(BUILD_DIR)/main.exe

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P)
	$(CC) $(CFLAGS) -c $< -o $@

$(MKDIR_P):
	@mkdir -p $(BUILD_DIR)

clean:
	$(RM) $(BUILD_DIR)/*.o $(EXEC)

ifeq ($(OS),Windows_NT)
    RM = del /Q
    MKDIR_P = @if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
else
    RM = rm -f
    MKDIR_P = mkdir -p $(BUILD_DIR)
endif

.PHONY: all clean
