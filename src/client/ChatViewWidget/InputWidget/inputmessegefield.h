#pragma once

#include <QTextEdit>

class InputMessageField final : public QTextEdit
{
    Q_OBJECT
public:
    explicit InputMessageField(QWidget* parent = nullptr);

private:
    void setupUi();
    void setupConnections();

    void onTextChanged();

private:
    const int _minHeight{ 36 };
    const int _maxHeight{ 200 };
};
