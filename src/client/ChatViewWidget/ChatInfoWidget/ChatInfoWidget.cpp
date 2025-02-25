#include "ChatInfoWidget.h"

#include <QLabel>
#include <QVBoxLayout>

ChatInfoWidget::ChatInfoWidget(QWidget* parent) : _clientName{ new QLabel(parent) } { setupUi(); }

void ChatInfoWidget::changeChatInfo(const QString& clientName) { _clientName->setText(clientName); }

void ChatInfoWidget::setupUi()
{
    _clientName->setText("Undefined");

    const auto vLayout = new QVBoxLayout();
    const auto hLayout = new QHBoxLayout();

    hLayout->addWidget(_clientName);

    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}