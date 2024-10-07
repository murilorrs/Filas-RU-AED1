# Variáveis
CC = gcc
CFLAGS = -Iinclude -Wall -g
SRC = $(wildcard src/*.c)
OBJ_DIR = build/obj
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))
TARGET = build/restaurante

# Cria o diretório build e build/obj se não existir
$(shell mkdir -p $(OBJ_DIR))

# Regra padrão (default)
all: $(TARGET)

# Linka os objetos para criar o executável
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Compila os arquivos .c em .o
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Executar o programa
run: all
	./$(TARGET)
