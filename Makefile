# Compilador C++
CXX = g++

# Flags do compilador: -std=c++17 para usar recursos modernos, -g para debug, -Wall para avisos
CXXFLAGS = -std=c++17 -g -Wall

# Diretório de includes
INCLUDES = -Iinclude

# Diretório de fontes
SRCDIR = src

# Diretório de build (onde os arquivos compilados irão parar)
BUILDDIR = build

# Nome do executável final
EXECUTABLE = $(BUILDDIR)/clinica


# --- Detecção Automática de Arquivos ---

# Encontra todos os arquivos .cpp dentro de src e suas subpastas
SOURCES := $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)

# Gera os nomes dos arquivos objeto (.o) que serão criados no diretório de build
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))


# --- Regras do Makefile ---

# A regra padrão, que é executada quando você digita apenas "make"
# Depende do executável final.
all: $(EXECUTABLE)

# Regra para linkar todos os arquivos objeto (.o) e criar o executável final
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(@D) # Cria o diretório de build se ele não existir
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo .cpp em um arquivo .o
# Compila fontes de $(SRCDIR) para objetos em $(BUILDDIR)
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D) # Cria os subdiretórios em build se necessário
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	@echo "Limpando arquivos de build..."
	@rm -rf $(BUILDDIR)

# compilar e executar o programa de uma só vez
run: all
	@echo "Executando o programa..."
	@./$(EXECUTABLE)

.PHONY: all clean run