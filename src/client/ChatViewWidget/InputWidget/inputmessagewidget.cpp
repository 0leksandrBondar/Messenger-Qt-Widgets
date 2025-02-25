#include "inputmessagewidget.h"
#include "inputmessegefield.h"

#include <QBoxLayout>
#include <QFileDialog>
#include <QPushButton>

InputMessageWidget::InputMessageWidget(QWidget* parent)
    : QWidget(parent),
      _sendButton{ new QPushButton(QStringLiteral("Send")) },
      _fileButton{ new QPushButton(QStringLiteral("File")) },
      _inputMessageField{ new InputMessageField() }
{
    setupUi();
    setupConnections();
}

void InputMessageWidget::onSendButtonClicked()
{
    if (_inputMessageField->toPlainText().isEmpty() && _filePath.isEmpty())
        return;

    emit sendMessage(_inputMessageField->toPlainText(), _filePath);
    _inputMessageField->clear();
    _filePath.clear();
}

void InputMessageWidget::onFileButtonClicked()
{
    _filePath
        = QFileDialog::getOpenFileName(this, tr("select file"), QString(), tr("All files (*.*)"));
}

void InputMessageWidget::setupUi()
{
    setupLayout();
    _sendButton->setFixedHeight(_inputMessageField->height());
    _fileButton->setFixedHeight(_inputMessageField->height());
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void InputMessageWidget::setupLayout()
{
    const auto vLayout = new QVBoxLayout();
    const auto hLayout = new QHBoxLayout();

    hLayout->addWidget(_fileButton);
    hLayout->addWidget(_inputMessageField);
    hLayout->addWidget(_sendButton);

    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}

void InputMessageWidget::setupConnections()
{
    connect(_sendButton, &QPushButton::clicked, this, &InputMessageWidget::onSendButtonClicked);
    connect(_fileButton, &QPushButton::clicked, this, &InputMessageWidget::onFileButtonClicked);
}
