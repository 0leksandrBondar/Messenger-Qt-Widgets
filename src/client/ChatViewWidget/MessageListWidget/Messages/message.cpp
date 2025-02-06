#include "message.h"

#include <QBoxLayout>
#include <QLabel>

Message::Message(const QString& message, const QString& filePath, bool isOwnMessage,
                 QWidget* parent)
    : QWidget(parent),
      _isOwnMessage(isOwnMessage),
      _pixmap{ QPixmap(filePath) },
      _label{ new QLabel(message) },
      _imageLabel{ new QLabel() }
{
    composeMessageWidget();
}

void Message::composeMessageWidget()
{
    const auto vLayout = new QVBoxLayout();
    const auto hLayout = new QHBoxLayout();

    auto label = _label->text();

    if (!_pixmap.isNull())
    {
        _imageLabel->setPixmap(
            _pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        _imageLabel->setAlignment(Qt::AlignCenter);
        vLayout->addWidget(_imageLabel);
    }

    if (!_label->text().isEmpty())
    {
        _label->setWordWrap(true);
        _label->setStyleSheet(QString("background-color: %1; color: white;"
                                      "padding: 8px; border-radius: 12px;")
                                  .arg(_isOwnMessage ? "#0078D4" : "#505050"));
        vLayout->addWidget(_label);
    }

    if (_isOwnMessage)
    {
        hLayout->addStretch();
        hLayout->addLayout(vLayout);
    }
    else
    {
        hLayout->addLayout(vLayout);
        hLayout->addStretch();
    }

    hLayout->setContentsMargins(10, 5, 10, 5);
    setLayout(hLayout);
}