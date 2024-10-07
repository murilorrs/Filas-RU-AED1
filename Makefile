# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Flags de compilação (encontrando todos os subdiretórios de include)
CFLAGS = $(addprefix -I,$(shell find $(INCLUDE_DIR) -type d)) -Wall -g

# Encontrar todos os arquivos .c
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
EXEC = $(BUILD_DIR)/restaurante

# Regra padrão
all: $(EXEC)

# Linkagem final do executável
$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	gcc -o $@ $^

# Compilação dos arquivos .c para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
