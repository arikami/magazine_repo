AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = src/Startup/splash.gb
OBJS = src/Startup/splash.o

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf $(BIN) $(OBJS) *~

