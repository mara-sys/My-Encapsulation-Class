#include
#src
#bin
#

TARGET = ./tests/cout_format
EXE = $(notdir $(TARGET)).exe

#CURT_DIR = $(shell pwd)
CURT_DIR = .
INC_PATH = $(CURT_DIR)/include
SRC_PATH = $(CURT_DIR)/src
BUILD_PATH = $(CURT_DIR)/build

INC_FILE_PATH = $(wildcard $(INC_PATH)/*)
SRC_FILE_PATH = $(wildcard $(SRC_PATH)/*)
SRC_FILE_PATH += $(TARGET)

INC_FILE = $(foreach ifile, $(INC_FILE_PATH), $(wildcard $(ifile)/*.h))
SRC_FILE = $(foreach sfile, $(SRC_FILE_PATH), $(wildcard $(sfile)/*.cpp))


INCLUDES = $(patsubst %, -I %, $(INC_FILE_PATH))
BUILD_FILE = $(patsubst %.cpp, build/%.o, $(notdir $(SRC_FILE)))

VPATH = $(SRC_FILE_PATH)

$(EXE) : $(BUILD_FILE)
	g++ $(BUILD_FILE) -o $(EXE)

# generate static lib
LIBENCAP = libencap.a
buildlib : $(BUILD_FILE)
	ar -r lib/$(LIBENCAP) $(BUILD_FILE)


$(BUILD_FILE) : build/%.o : %.cpp
	@echo $<
	g++ $(INCLUDES) -c $< -o $@


clean:
	rm -f ./build/*.o ./lib/* $(EXE)

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
