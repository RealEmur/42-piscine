SOURCES = main.c helpers.c map_validation.c maps.c square.c

CFLAGS = -Wall -Wextra -Werror

OUTPUT = bsq

all: $(SOURCES)
	gcc $(CFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)
