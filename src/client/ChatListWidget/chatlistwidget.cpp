#include "chatlistwidget.h"

#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

ChatListWidget::ChatListWidget(QWidget* parent)
    : QWidget(parent),
      _searchLine{ new QLineEdit() },
      _addChatButton{ new QPushButton(QStringLiteral("New")) },
      _chatListWidget{ new QListWidget() }
{
    setupUi();
    setupConnections();
}

void ChatListWidget::onChatSelectionChanged() const {}

void ChatListWidget::onAddChatButtonClicked() const
{
    if (!_searchLine->text().isEmpty())
    {
        createChat(_searchLine->text());
        _searchLine->clear();
    }
}

void ChatListWidget::onSplitterResized(int pos /*unused*/, int index /*unused*/) const
{
    for (int i = 0; i < _chatListWidget->count(); ++i)
    {
        auto* it = _chatListWidget->item(i);
        it->setSizeHint(QSize(width(), 50));
    }
}

void ChatListWidget::setupUi()
{
    _chatListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    const auto vLayout = new QVBoxLayout();
    const auto hLayout = new QHBoxLayout();

    hLayout->addWidget(_addChatButton);
    hLayout->addWidget(_searchLine);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(_chatListWidget);

    setLayout(vLayout);
}

void ChatListWidget::setupConnections()
{
    connect(_addChatButton, &QPushButton::clicked, this, &ChatListWidget::onAddChatButtonClicked);
    connect(_chatListWidget, &QListWidget::itemSelectionChanged, this,
            &ChatListWidget::onChatSelectionChanged);
}

void ChatListWidget::createChat(const QString& chatName) const
{
    auto* item = new QListWidgetItem();
    item->setText(chatName);
    item->setTextAlignment(Qt::AlignmentFlag::AlignCenter);
    item->setSizeHint(QSize(width(), 70));
    _chatListWidget->addItem(item);
    _chatListWidget->setCurrentItem(item);
}
