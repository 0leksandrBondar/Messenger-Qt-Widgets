#include "Style.h"

#include <qfile.h>
#include <qguiapplication.h>
#include <QStyleHints>
namespace Style
{
    bool isDarkSystemTheme()
    {
#if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
        const auto scheme =  QGuiApplication::styleHints();
        return scheme->colorScheme() == Qt::ColorScheme::Dark;
#else
        const QPalette defaultPalette;
        const auto text = defaultPalette.color(QPalette::WindowText);
        const auto window = defaultPalette.color(QPalette::Window);
        return text.lightness() > window.lightness();
#endif // QT_VERSION
    }

    QString getStyle(std::filesystem::path path)
    {
        QFile file(path);
        if (file.open(QIODevice::ReadOnly))
        {
            return file.readAll();
        }
        return "";
    }
} // namespace Style