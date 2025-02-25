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

    auto containerWidget = new QWidget();

    const auto containerLayout = new QVBoxLayout(containerWidget);

    if (!_pixmap.isNull())
    {
        _imageLabel->setPixmap(
            _pixmap.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        _imageLabel->setAlignment(Qt::AlignCenter);
        containerLayout->addWidget(_imageLabel);
    }

    if (!_label->text().isEmpty())
    {
        _label->setWordWrap(true);
        _label->setStyleSheet(
            "background-color: limegreen;border-radius: 10px; padding: 10px; font: bold 18px Arial; color: black;");
        _label->setMaximumWidth(300);
        _label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        containerLayout->addWidget(_label);
    }

    containerWidget->setLayout(containerLayout);
    vLayout->addWidget(containerWidget);

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

    setLayout(hLayout);
}
