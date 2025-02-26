#include "welcomewidget.h"

#include "Style/Style.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

WelcomeWidget::WelcomeWidget(QWidget* parent)
    : QWidget(parent),
      _welcomeLabel(new QLabel()),
      _loginButton{ new QPushButton(QStringLiteral("Login")) },
      _nameInputLine{ new QLineEdit() }
{
    setupUi();
    setupConnections();
}

void WelcomeWidget::onLoginButtonClicked()
{
    if (_nameInputLine->text().isEmpty())
        return;

    emit loginButtonClicked();
}

QString WelcomeWidget::getUserName() const { return _nameInputLine->text(); }

void WelcomeWidget::setupUi()
{
    _welcomeLabel->setAlignment(Qt::AlignCenter);
    _welcomeLabel->setStyleSheet("color: limegreen; font: bold 72px Arial;");
    _welcomeLabel->setText(QStringLiteral("Welcome to DarkSpace"));

    _nameInputLine->setMinimumHeight(50);
    _nameInputLine->setMaximumWidth(500);
    _nameInputLine->setMinimumWidth(200);
    _nameInputLine->setFocusPolicy(Qt::ClickFocus);
    _nameInputLine->setPlaceholderText(QStringLiteral("Enter username..."));

    _loginButton->setFixedWidth(500);

    if (Style::isDarkSystemTheme())
        setupDarkTheme();
    else
        setupLightTheme();

    const auto layout = new QVBoxLayout();
    const auto labelLayout = new QVBoxLayout();
    const auto inputLayout = new QVBoxLayout();

    labelLayout->addWidget(_welcomeLabel);

    inputLayout->setSpacing(20);
    inputLayout->addWidget(_nameInputLine);
    inputLayout->addWidget(_loginButton);
    inputLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

    layout->setSpacing(10);
    layout->addLayout(labelLayout);
    layout->addLayout(inputLayout);

    setLayout(layout);
}

void WelcomeWidget::setupDarkTheme() const
{
    _loginButton->setStyleSheet(Style::getStyle("Style/WelcomePage/Dark/QPushButtonStyle.qss"));
    _nameInputLine->setStyleSheet(Style::getStyle("Style/WelcomePage/Dark/QLineEditStyle.qss"));
}

void WelcomeWidget::setupLightTheme() const
{
    _loginButton->setStyleSheet(Style::getStyle("Style/WelcomePage/Light/QPushButtonStyle.qss"));
    _nameInputLine->setStyleSheet(Style::getStyle("Style/WelcomePage/Light/QLineEditStyle.qss"));
}

void WelcomeWidget::setupConnections()
{
    connect(_loginButton, &QPushButton::clicked, this, &WelcomeWidget::onLoginButtonClicked);
    connect(_nameInputLine, &QLineEdit::returnPressed, this, &WelcomeWidget::onLoginButtonClicked);
}
