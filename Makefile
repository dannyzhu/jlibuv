# user.agent dylib for mac
#


TARGET = libjuv.dylib

CC = clang++

DEBUG = -g -DDEBUG 
# -DTRACE.ENABLE
CINCLUDE = -I/System/Library/Frameworks/JavaVM.framework/Versions/Current/Headers \
		-I./src/main/native \
        -I./out/include \
        -I/opt/local/include \

CLIB = -L/opt/local/lib \
       -L/System/Library/Frameworks/JavaVM.framework/Versions/CurrentJDK/Libraries

CFLAGS = -w -O2 -Wall -c $(DEBUG) $(CINCLUDE)
LFLAGS = -Wall $(DEBUG) $(CLIB) -luv -framework JavaVM

OBJS.DIR = out/mac_java_objs
SRC.DIR = src/main/native

OBJS = \
$(OBJS.DIR)/libuv-java-async.o \
$(OBJS.DIR)/libuv-java-check.o \
$(OBJS.DIR)/libuv-java-child_process.o \
$(OBJS.DIR)/libuv-java-constants.o \
$(OBJS.DIR)/libuv-java-context.o \
$(OBJS.DIR)/libuv-java-exception.o \
$(OBJS.DIR)/libuv-java-file.o \
$(OBJS.DIR)/libuv-java-file_event.o \
$(OBJS.DIR)/libuv-java-file_poll.o \
$(OBJS.DIR)/libuv-java-handle.o \
$(OBJS.DIR)/libuv-java-idle.o \
$(OBJS.DIR)/libuv-java-loop.o \
$(OBJS.DIR)/libuv-java-misc.o \
$(OBJS.DIR)/libuv-java-os.o \
$(OBJS.DIR)/libuv-java-pipe.o \
$(OBJS.DIR)/libuv-java-process.o \
$(OBJS.DIR)/libuv-java-signal.o \
$(OBJS.DIR)/libuv-java-stats.o \
$(OBJS.DIR)/libuv-java-stream.o \
$(OBJS.DIR)/libuv-java-tcp.o \
$(OBJS.DIR)/libuv-java-timer.o \
$(OBJS.DIR)/libuv-java-tty.o \
$(OBJS.DIR)/libuv-java-udp.o \

all : $(TARGET) 

$(TARGET) : $(OBJS) 
	$(CC) -dynamiclib -o $(TARGET) $(OBJS) $(LFLAGS)

$(OBJS.DIR)/libuv-java-async.o : $(SRC.DIR)/async.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-check.o : $(SRC.DIR)/check.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-child_process.o : $(SRC.DIR)/child_process.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-constants.o : $(SRC.DIR)/constants.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-context.o : $(SRC.DIR)/context.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-exception.o : $(SRC.DIR)/exception.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-file.o : $(SRC.DIR)/file.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-file_event.o : $(SRC.DIR)/file_event.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-file_poll.o : $(SRC.DIR)/file_poll.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-handle.o : $(SRC.DIR)/handle.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-idle.o : $(SRC.DIR)/idle.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-loop.o : $(SRC.DIR)/loop.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-misc.o : $(SRC.DIR)/misc.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-os.o : $(SRC.DIR)/os.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-pipe.o : $(SRC.DIR)/pipe.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-process.o : $(SRC.DIR)/process.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-signal.o : $(SRC.DIR)/signal.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-stats.o : $(SRC.DIR)/stats.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-stream.o : $(SRC.DIR)/stream.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-tcp.o : $(SRC.DIR)/tcp.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-timer.o : $(SRC.DIR)/timer.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-tty.o : $(SRC.DIR)/tty.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS.DIR)/libuv-java-udp.o : $(SRC.DIR)/udp.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm $(OBJS)

