

# Compilador C++
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++17 -g -Wall

# Diretório de includes
INCLUDES = -Iinclude

# Diretório de fontes
SRCDIR = src

# Diretório de build
BUILDDIR = build

# Nome do executável final
EXECUTABLE = $(BUILDDIR)/clinica.exe

# --- Detecção Automática de Arquivos ---
SOURCES := $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# --- Regras do Makefile ---
.PHONY: all clean run

# A regra padrão
all: $(EXECUTABLE)

# Regra para linkar os arquivos e criar o executável
$(EXECUTABLE): $(OBJECTS)
	@echo "--> Linkando para criar o executavel: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo .cpp em um .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "--> Compilando: $<"
	@mkdir "$(subst /,\,$(@D))" 2>nul || echo.
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	@echo "Limpando arquivos de build..."
	-rmdir /S /Q "$(subst /,\,$(BUILDDIR))" 2>nul || echo.

# Regra para compilar e executar
run: all
	@echo "Executando o programa..."
	@"$(subst /,\,$(EXECUTABLE))"