#include
#src
#bin
#build
#lib		Store the generated lib file
#exe_test	Store the executable file

TARGET = ./tests/cout_format
EXE = $(notdir $(TARGET)).exe

#CURT_DIR = $(shell pwd)
CURT_DIR = .
INC_PATH = $(CURT_DIR)/include
SRC_PATH = $(CURT_DIR)/src
BUILD_PATH = $(CURT_DIR)/build

#INC_FILE_PATH = $(wildcard $(INC_PATH)/*)
#SRC_FILE_PATH = $(wildcard $(SRC_PATH)/*)
INC_FILE_PATH = $(shell find $(INC_PATH) -type d)
SRC_FILE_PATH = $(shell find $(SRC_PATH) -type d)
SRC_FILE_PATH += $(TARGET)

INC_FILE = $(foreach ifile, $(INC_FILE_PATH), $(wildcard $(ifile)/*.h))
SRC_FILE = $(foreach sfile, $(SRC_FILE_PATH), $(wildcard $(sfile)/*.cpp))


INCLUDES = $(patsubst %, -I %, $(INC_FILE_PATH))
BUILD_FILE = $(patsubst %.cpp, build/%.o, $(notdir $(SRC_FILE)))

VPATH = $(SRC_FILE_PATH)

$(EXE) : build_dir $(BUILD_FILE)
	g++ -std=c++17 $(BUILD_FILE) -o $(EXE)
	mv $(EXE) ./exe_test/

# generate static lib
LIBENCAP = libencap.a
buildlib : $(BUILD_FILE)
	ar -r lib/$(LIBENCAP) $(BUILD_FILE)


$(BUILD_FILE) : build/%.o : %.cpp $(INC_FILE)
	@echo $<
	g++ -std=c++17 $(INCLUDES) -c $< -o $@

build_dir:
	mkdir -p $(CURT_DIR)/build
	mkdir -p $(CURT_DIR)/lib
	mkdir -p $(CURT_DIR)/exe_test

clean:
	rm -f ./build/*.o ./lib/* $(EXE) ./exe_test/*.exe

test:
	@echo "EXE                   $(EXE)"
	@echo "TARGET:               $(TARGET)"
	@echo "CURT_DIR              $(CURT_DIR)"
	@echo "INC_PATH              $(INC_PATH)"
	@echo "SRC_PATH              $(SRC_PATH)"
	@echo "INC_FILE_PATH         $(INC_FILE_PATH)"
	@echo "SRC_FILE_PATH         $(SRC_FILE_PATH)"
	@echo "INC_FILE              $(INC_FILE)"
	@echo "SRC_FILE              $(SRC_FILE)"
	@echo "BUILD_FILE            $(BUILD_FILE)"
	@echo "VPATH                 $(VPATH)"