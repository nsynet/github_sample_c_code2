VERSION  =1.00
CC   =gcc
DEBUG   =-g
CFLAGS  =-Wall
SOURCES   =$(wildcard ./source/*.c)
INCLUDES   =-I ./include
LIB_NAMES  =-linih
LIB_PATH  =-L ./lib
OBJ   =$(patsubst %.c, %.o, $(SOURCES))
TARGET  =app

#links
$(TARGET):$(OBJ)
	@mkdir -p output
	$(CC) $(OBJ) $(LIB_PATH) $(LIB_NAMES) -o output/$(TARGET)$(VERSION)
	@rm -rf $(OBJ)
 
#compile
%.o: %.c
	$(CC) $(INCLUDES) $(DEBUG) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	@echo "Remove linked and compiled files......"
	rm -rf $(OBJ) $(TARGET) output
