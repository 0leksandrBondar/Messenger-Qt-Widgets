#include <QString>

#include <filesystem>

namespace Style
{
    bool isDarkSystemTheme();
    QString getStyle(std::filesystem::path path);
} // namespace Style