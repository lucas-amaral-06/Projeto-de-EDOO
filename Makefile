# Compilador C++
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++23 -g -Wall

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

# Detecta sistema operacional
ifeq ($(OS),Windows_NT)
    RM = rmdir /S /Q
    MKDIR = if not exist "$(subst /,\,$(1))" mkdir "$(subst /,\,$(1))"
    EXE_EXT = .exe
    RUN = cmd /c "$(subst /,\,$(EXECUTABLE))"
else
    RM = rm -rf
    MKDIR = mkdir -p $(1)
    EXE_EXT =
    RUN = ./$(EXECUTABLE)
endif

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "--> Linkando para criar o executável: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar cada arquivo .cpp em um .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "--> Compilando: $<"
	$(call MKDIR,$(@D))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Limpando arquivos de build..."
	$(RM) "$(subst /,\,$(BUILDDIR))"

run: all
	@echo "Executando o programa..."
	$(RUN)
