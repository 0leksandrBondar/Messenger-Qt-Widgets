#include "inputmessegefield.h"

InputMessageField::InputMessageField(QWidget* parent) : QTextEdit(parent)
{
    setupUi();
    setupConnections();
}

void InputMessageField::setupUi()
{
    setFixedHeight(36);
    setFontPointSize(16);
    setPlaceholderText(QStringLiteral("Enter message..."));
}

void InputMessageField::setupConnections()
{
    connect(this, &QTextEdit::textChanged, this, &InputMessageField::onTextChanged);
}

void InputMessageField::onTextChanged()
{
    const int docHeight = document()->size().height() + 10 ;
    setFixedHeight(qMin(_maxHeight, qMax(_minHeight, docHeight)));
}
