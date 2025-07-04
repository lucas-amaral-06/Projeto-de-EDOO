# SysMed C++ - Sistema de Atendimento Médico
Esse é um sistema de linha de comando que simula o gerenciamento de prontuários eletrônicos de uma clínica, desenvolvido em C++ como um projeto para a disciplina de EDOO.

## 📖 Sobre o Projeto
O **SysMed C++** é uma simulação de um sistema de software de uma clínica médica. O objetivo principal do projeto foi aplicar de forma prática os quatro pilares da Programação Orientada a Objetos (Abstração, Encapsulamento, Herança e Polimorfismo) além de boas práticas de arquitetura de software como a separação de responsabilidade em camadas (Core, UI, Dados).

O sistema permite o cadastro de médicos e pacientes e a visualização desses cadastros, tudo através de uma interface de terminal interativa, com um banco de dados in-memory para simulação.

## 🧑‍💻 Conceitos de POO Aplicados
1. **Encapsulamento** - Os atributos das nossas classes são mantidos como `private`. O acesso a eles é controlado através de métodos públicos (`getters` e `setters`), protegendo a integridados dos dados.
2. **Herança** - Fizemos uso de reutilização de código e a criação de uma hierarquia lógica por meio da relação "é um(a)":
   - `Paciente` é uma `Pessoa`.
   - `Medico` é uma `Pessoa`.
   - `Recepcionista` é uma `Pessoa`.
   - `Evolucao`, `Receita` e `Atestado` são tipos de `DocumentoClinico`.
  
3. **Polimorfismo** - Através de funções virtuais e sobrescrita de métodos, tratamos objetos de classes diferentes de forma uniforme. O método `exibirDados()` da classe Pessoa é sobrescrito em `Paciente`, `Médico` e `Recepcionista` para exibir informações específicas de cada um.
4. **Abstração** - As classes modelam conceitos do mundo real, focando apenas nos atributos e comportamentos relevantes para o sistema e escondendo a complexidade interna.
5. **Composição** - Demonstramos a relação "tem um(a)" para construir objetos complexos a partir de outro mais simples.
    - Um `Paciente` tem um `Prontuario`.
    - Um `Medico` tem uma `Agenda`.
    - Um `Prontuario` tem uma lista de `DocumentosClinicos`

## ✨ Funcionalidades Implementadas
- **Cadastro de Usuários**: Sistema de registro para médicos, pacientes e recepcionistas, com menu distintos e coleta de dados via terminal.
- **Banco de dados em Memória**: Uma camada de dados simulada que é pré-populada com médicas, pacientes, consultas e registros em prontuários para permitir uma boa simulação.
- **Listagem de Cadastros**: Funcionalidade para visualizar listas completas de todos os médicos e recepcionistas registrados no sistema.

## 🛠️ Estrutura do Projeto
```
ClinicaPOO/
├── include/            # Arquivos de cabeçalho (.hpp)
│   ├── db/             # Interface do banco de dados em memória
│   └── ui/             # Interfaces dos módulos de UI (Menu, Auth, etc.)
│   Pessoa.hpp          # Interfaces das classes de negócio (Pessoa, Paciente, etc.)
|   ...           
│
├── src/                # Arquivos de implementação (.cpp)
│   ├── core/           # Implementação das classes de negócio
│   ├── db/             # Implementação do banco de dados
│   ├── ui/             # Implementação da lógica de UI
│   └── main.cpp        # Ponto de entrada e orquestração da aplicação
│
├── build/              # Diretório para os arquivos compilados (criado pelo Makefile)
│
└── Makefile            # Automatiza o processo de compilação
```

## 🛠️ Pré-requisitos
Para compular e executar o projeto você precisará de:
- Um compilador C++ com suporte a C++23 (ex: `g++`)
- A ferramenta `make` para automatizar a compilação

## 🚀 Como Executar
1. Clone o repositório e vá até a pasta do projeto
  ```bash
  git clone https://github.com/lucas-amaral-06/Projeto-de-EDOO.git
  cd Projeto-de-EDOO
  ```
2. Compile o projeto
  ```bash
  make clean && make run
  ```

## 👤 Autores
| <img src="https://avatars.githubusercontent.com/u/151575079?s=400&u=96fac0907f9100c143dc9f46242cacdf17af240f&v=4" alt="Lucas Torres" width="70" height="70"> | <img src="https://avatars.githubusercontent.com/u/204923746?v=4" alt="Lucas Amaral" width="70" height="70"> | <img src="https://img.freepik.com/premium-vector/user-profile-icon-flat-style-member-avatar-vector-illustration-isolated-background-human-permission-sign-business-concept_157943-15752.jpg" alt="Gryghor Camonni" width="70" height="70"> | <img src="https://img.freepik.com/premium-vector/user-profile-icon-flat-style-member-avatar-vector-illustration-isolated-background-human-permission-sign-business-concept_157943-15752.jpg" alt="Valber Roberto" width="70" height="70"> ||
| ------------------------------------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------- |
| [Lucas Torres](https://github.com/lucaastorres7)                                                                                                                      | [Lucas Amaral](https://github.com/lucas-amaral-06)                                                                    | [Gryghor Camonni](https://github.com/gryghor)                                                                    | [Valber Roberto]()                                                                   |
