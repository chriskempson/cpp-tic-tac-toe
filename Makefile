SRC_DIR = Tic-tac-toe
OUTPUT_DIR = Release

OBJS = $(SRC_DIR)/*.cpp
OBJ_NAME = tic-tac-toe

COMPILER_FLAGS = -w -I/usr/include/SDL2
LINKER_FLAGS = -lSDL2 -lSDL2_mixer

# Targets
all : $(OBJS)
	mkdir -p $(OUTPUT_DIR)
	cp -r $(SRC_DIR)/images $(OUTPUT_DIR)
	cp -r $(SRC_DIR)/sounds $(OUTPUT_DIR)
	g++ $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) \
		-o $(OUTPUT_DIR)/$(OBJ_NAME)

.PHONY: clean
clean:
	rm -fr $(OUTPUT_DIR)

.PHONY: run
run:
	cd $(OUTPUT_DIR); ./$(OBJ_NAME)

.PHONY: install
install:
	mkdir -p /opt/$(OBJ_NAME)
	cp -fr $(OUTPUT_DIR)/* /opt/$(OBJ_NAME)
	cp $(SRC_DIR)/icon128.bmp /opt/$(OBJ_NAME)
	cp $(SRC_DIR)/run.sh /opt/$(OBJ_NAME)
	cp $(SRC_DIR)/$(OBJ_NAME).desktop /usr/share/applications

.PHONY: uninstall
uninstall:
	rm -fr /opt/$(OBJ_NAME)
	rm /usr/share/applications/$(OBJ_NAME).desktop
