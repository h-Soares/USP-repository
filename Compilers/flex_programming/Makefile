# Variáveis
LEX_FILE = base_program.l
OUTPUT = program

# Detectar sistema operacional
ifeq ($(OS),Windows_NT)
    RM = del /f
else
    RM = rm -f
endif

# Regra principal: compilar o programa
all: $(OUTPUT)

# Compilar e gerar o executável
$(OUTPUT): lex.yy.c
	gcc lex.yy.c -o $(OUTPUT) -LC:\GnuWin32\lib -lfl

# Gerar o arquivo lex.yy.c a partir do arquivo .l
lex.yy.c:
	flex $(LEX_FILE)

# Executar o programa
run: $(OUTPUT)
	./$(OUTPUT)

# Limpar arquivos gerados
clean:
	$(RM) lex.yy.c $(OUTPUT).exe