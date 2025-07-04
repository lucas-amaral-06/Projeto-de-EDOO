#ifndef DATA_UTILS_HPP
#define DATA_UTILS_HPP

#include <string>
#include <chrono>
#include <ctime>

namespace DataUtils {
    inline std::string getDataAtualFormatada() {
        const auto agora = std::chrono::system_clock::now();
        const auto data_t = std::chrono::system_clock::to_time_t(agora);
        
        // Usamos um buffer para segurança com localtime
        std::tm tm_local;
        #ifdef _WIN32
            localtime_s(&tm_local, &data_t); // Versão segura para Windows
        #else
            localtime_r(&data_t, &tm_local); // Versão segura para Linux/macOS
        #endif

        char buffer[11]; // "dd/mm/yyyy\0"
        std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", &tm_local);
        return buffer;
    }
}

#endif