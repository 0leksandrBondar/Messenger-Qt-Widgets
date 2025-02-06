#include "clientwidget.h"
#include "ChatListWidget/chatlistwidget.h"
#include "ChatViewWidget/chatviewwidget.h"

#include <QLineEdit>
#include <QSplitter>
#include <QVBoxLayout>

ClientWidget::ClientWidget(QWidget* parent)
    : QWidget(parent),
      _splitter{ new QSplitter() },
      _chatListWidget{ new ChatListWidget() },
      _chatViewWidget{ new ChatViewWidget() }
{
    setupUi();
    setupConnections();
}

void ClientWidget::setupUi()
{
    const auto vLayout = new QVBoxLayout();
    const auto hLayout = new QHBoxLayout();

    setupSplitter();

    hLayout->addWidget(_splitter);
    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}

void ClientWidget::setupConnections()
{
    connect(_splitter, &QSplitter::splitterMoved, _chatListWidget,
            &ChatListWidget::onSplitterResized);
}

void ClientWidget::setupSplitter() const
{
    _splitter->addWidget(_chatListWidget);
    _splitter->addWidget(_chatViewWidget);

    _chatListWidget->setMinimumWidth(400);

    _splitter->setCollapsible(0, false);
    _splitter->setCollapsible(1, false);

    _splitter->setStretchFactor(0, 3);
    _splitter->setStretchFactor(1, 7);
}
